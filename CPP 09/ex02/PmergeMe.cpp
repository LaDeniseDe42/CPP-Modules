/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:32:01 by root              #+#    #+#             */
/*   Updated: 2023/12/12 15:51:29 by qdenizar         ###   ########.fr       */
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
        this->_deque = objectToCopy._deque;
        this->_vit = objectToCopy._vit;
        this->_deq= objectToCopy._deq;
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

void    PmergeMe::filldeque(long long int numberOfNumbers, char **argv)
{
    int j = 1;
    for (int i = 0; i < numberOfNumbers; i++)
        this->_deque.push_back(std::atoll(argv[j++]));
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

void    PmergeMe::printdeque(int supFive)
{
    std::cout << "Before:  ";
    if (supFive <= 5)
    {
        for (this->_deq= this->_deque.begin(); this->_deq!= this->_deque.end(); this->_deq++)
            std::cout << *this->_deq<< " ";
    }
    else
    {
        int z = 0;
        for (this->_deq= this->_deque.begin(); this->_deq!= this->_deque.end(); this->_deq++)
        {
            std::cout << *this->_deq<< " ";
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

void    PmergeMe::mergeDe(int supFive)
{
    std::deque<long long int> tmp;
    std::deque<long long int>::iterator it;

    for (it = this->_deque.begin(); it != this->_deque.end(); it++)
        tmp.push_back(*it);
    tmp = fordJohnsonDe(tmp, supFive);
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
                long long int nbChange = tmp[i];
                int j = i - 1;

                while (j >= 0 && tmp[j] > nbChange)
                {
                    tmp[j + 1] = tmp[j];
                    --j;
                }
                tmp[j + 1] = nbChange;
            }
        }
        return (tmp);
    }
    
    std::deque<long long int>    PmergeMe::fordJohnsonDe(std::deque<long long int> tmp, int nbNb)
    {
        std::deque<long long int>::iterator it;
        std::deque<long long int> left;
        std::deque<long long int> right;
        if (nbNb > 5)
        {
            
            for (it = tmp.begin(); it != tmp.end(); it++)
            {
                if (it < tmp.begin() + (nbNb / 2))
                    left.push_back(*it);
                else
                    right.push_back(*it);
            }
            left = fordJohnsonDe(left, nbNb / 2);
            right = fordJohnsonDe(right, nbNb / 2);
            tmp.clear();
            std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(tmp));        
        }
        else
        {
            for (size_t i = 1; i < tmp.size(); ++i)
            {
                long long int nbChange = tmp[i];
                int j = i - 1;

                while (j >= 0 && tmp[j] > nbChange)
                {
                    tmp[j + 1] = tmp[j];
                    --j;
                }
                tmp[j + 1] = nbChange;
            }
        }
        return (tmp);
        
    }