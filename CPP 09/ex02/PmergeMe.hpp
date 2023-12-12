/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:31:47 by root              #+#    #+#             */
/*   Updated: 2023/12/12 15:50:49 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>

class PmergeMe
{
private:
    std::vector<long long int> _vector;
    std::deque<long long int> _deque;
    std::vector<long long int>::iterator _vit;
    std::deque<long long int>::iterator _deq;
public:
    PmergeMe();//default constructor
    ~PmergeMe();//destructor
    PmergeMe(const PmergeMe &	newPmergeMe); //cpy constructor
    PmergeMe& operator=(const PmergeMe& objectToCopy); //Copy assignment operator

    void    fillVector(long long int nb, char  **argv);
    void    filldeque(long long int nb, char **argv);
    void    printVector(int supFive);
    void    printdeque(int supFive);
    void    mergeVec(int supFive);
    void    mergeDe(int supFive);
    std::vector<long long int>  fordJohnsonVec(std::vector<long long int> tmp, int nbNb);
    std::deque<long long int>    fordJohnsonDe(std::deque<long long int> tmp, int nbNb);
    int     verifArg(long long int numberOfNumbers, char **argv);
};