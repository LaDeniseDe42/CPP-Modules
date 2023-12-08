/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:32:01 by root              #+#    #+#             */
/*   Updated: 2023/12/08 13:10:31 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
}

PmergeMe::~PmergeMe()
{
    
}

PmergeMe::PmergeMe(const PmergeMe &	newPmergeMe)
{
    *this = newPmergeMe;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& objectToCopy)
{
    if (this != &objectToCopy)
    {
        this->_vector = objectToCopy._vector;
        this->_list = objectToCopy._list;
        this->_vit = objectToCopy._vit;
        this->_lit = objectToCopy._lit;
    }
    return (*this);
}

int     PmergeMe::verifArg(long long int numberOfNumbers, char **argv)
{
    for (int i = 1; i < numberOfNumbers +1; i++)
    {
        for (size_t k = 0; k < std::strlen(argv[i]); k++)
        {
            if (!std::isdigit(argv[i][k]))
                return (1);   
        }
    }
    return (0);
}

void    PmergeMe::fillVector(long long int numberOfNumbers, char **argv)
{
    int j = 1;
    for (int i = 0; i < numberOfNumbers; i++)
        this->_vector.push_back(std::atoll(argv[j++]));
}

void    PmergeMe::fillList(long long int numberOfNumbers, char **argv)
{
    int j = 1;
    for (int i = 0; i < numberOfNumbers; i++)
        this->_list.push_back(std::atoll(argv[j++]));
}

void    PmergeMe::printVector(int supFive)
{
    std::cout << "Before:  ";
    if (supFive <= 5)
    {
        for (this->_vit = this->_vector.begin(); this->_vit != this->_vector.end(); this->_vit++)
            std::cout << *this->_vit << " ";  
    }
    else
    {
        int z = 0;
        for (this->_vit = this->_vector.begin(); this->_vit != this->_vector.end(); this->_vit++)
        {
            std::cout << *this->_vit << " ";
            if (z == 4)
                break;
            z++;   
        }
        std::cout <<"[...]";
    }
    
    std::cout << std::endl;
}

void    PmergeMe::printList(int supFive)
{
    std::cout << "Before:  ";
    if (supFive <= 5)
    {
        for (this->_lit = this->_list.begin(); this->_lit != this->_list.end(); this->_lit++)
            std::cout << *this->_lit << " ";
    }
    else
    {
        int z = 0;
        for (this->_lit = this->_list.begin(); this->_lit != this->_list.end(); this->_lit++)
        {
            std::cout << *this->_lit << " ";
            if (z == 4)
                break;
            z++; 
        }
        std::cout <<"[...]";
    }
    std::cout << std::endl;
}

void    PmergeMe::mergeVec(int supFive)
{
    std::vector<long long int> tmp;
    std::vector<long long int>::iterator it;

    for (it = this->_vector.begin(); it != this->_vector.end(); it++)
        tmp.push_back(*it);
    //std::sort(tmp.begin(), tmp.end());
    tmp = fordJohnsonVec(tmp, supFive);
    std::cout << "After:  ";
    if (supFive <= 5)
    {
        for (it = tmp.begin(); it != tmp.end(); it++)
            std::cout << *it << " ";  
    }
    else
    {
        int z = 0;
        for (it = tmp.begin(); it != tmp.end(); it++)
        {
            std::cout << *it << " ";
            if (z == 4)
                break;
            z++;
        }
        std::cout <<"[...]";
    }
    std::cout << std::endl;
}

void    PmergeMe::mergeLi(int supFive)
{
    std::list<long long int> tmp;
    std::list<long long int>::iterator it;

    for (it = this->_list.begin(); it != this->_list.end(); it++)
        tmp.push_back(*it);
    //tmp.sort();
    tmp = fordJohnsonLi(tmp, supFive);
    std::cout << "After:  ";
    if (supFive <= 5)
    {
        for (it = tmp.begin(); it != tmp.end(); it++)
            std::cout << *it << " ";  
    }
    else
    {
        int z = 0;
        for (it = tmp.begin(); it != tmp.end(); it++)
        {
            std::cout << *it << " ";
            if (z == 4)
                break;
            z++;   
        }
        std::cout <<"[...]";
    }
    std::cout << std::endl;
}

    std::vector<long long int>  PmergeMe::fordJohnsonVec(std::vector<long long int> tmp, int nbNb)
    {
        std::vector<long long int>::iterator it;
        std::vector<long long int> left;
        std::vector<long long int> right;
        if (nbNb > 5)
        {
            for (it = tmp.begin(); it != tmp.end(); it++)
            {
                if (it < tmp.begin() + (nbNb / 2))
                    left.push_back(*it);
                else
                    right.push_back(*it);
            }
            left = fordJohnsonVec(left, nbNb / 2);
            right = fordJohnsonVec(right, nbNb / 2);
            tmp.clear();
            std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(tmp));        
        }
        else
        {
            for (size_t i = 1; i < tmp.size(); ++i)
            {
                long long int key = tmp[i];
                int j = i - 1;

                while (j >= 0 && tmp[j] > key)
                {
                    tmp[j + 1] = tmp[j];
                    --j;
                }
                tmp[j + 1] = key;
            }
        }
        return (tmp);
    }
    
    std::list<long long int>    PmergeMe::fordJohnsonLi(std::list<long long int> tmp, int nbNb)
    {
        std::list<long long int>::iterator it;
        std::list<long long int> left;
        std::list<long long int> right;
        if (nbNb > 5)
        {
            int i = 0;
            for (it = tmp.begin(); it != tmp.end(); ++it, ++i)
            {
                if (i < nbNb / 2)
                    left.push_back(*it);
                else
                    right.push_back(*it);
            }
            left = fordJohnsonLi(left, nbNb / 2);
            right = fordJohnsonLi(right, nbNb / 2);
            tmp.clear();
            std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(tmp));        
        }
        else
            tmp.sort();
        return (tmp);
        
    }