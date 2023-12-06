/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:32:01 by root              #+#    #+#             */
/*   Updated: 2023/12/06 15:11:27 by root             ###   ########.fr       */
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

void    PmergeMe::fillVector(long long int numberOfNumbers, char **argv)
{
    int j = 1;
    for (int i = 0; i < numberOfNumbers; i++)
        this->_vector.push_back(std::atoi(argv[j++]));
}

void    PmergeMe::fillList(long long int numberOfNumbers, char **argv)
{
    int j = 1;
    for (int i = 0; i < numberOfNumbers; i++)
        this->_list.push_back(std::atoi(argv[j++]));
}

void    PmergeMe::printVector()
{
    std::cout << "Vector: ";
    for (this->_vit = this->_vector.begin(); this->_vit != this->_vector.end(); this->_vit++)
        std::cout << *this->_vit << " ";
    std::cout << std::endl;
}

void    PmergeMe::printList()
{
    std::cout << "List: ";
    for (this->_lit = this->_list.begin(); this->_lit != this->_list.end(); this->_lit++)
        std::cout << *this->_lit << " ";
    std::cout << std::endl;
}

void    PmergeMe::mergeVec()
{
    std::vector<long long int> tmp;
    std::vector<long long int>::iterator it;

    for (it = this->_vector.begin(); it != this->_vector.end(); it++)
        tmp.push_back(*it);
    std::sort(tmp.begin(), tmp.end());
    std::cout << "Merged vector: ";
    for (it = tmp.begin(); it != tmp.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void    PmergeMe::mergeLi()
{
    std::list<long long int> tmp;
    std::list<long long int>::iterator it;

    for (it = this->_list.begin(); it != this->_list.end(); it++)
        tmp.push_back(*it);
    tmp.sort();
    std::cout << "Merged list: ";
    for (it = tmp.begin(); it != tmp.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}