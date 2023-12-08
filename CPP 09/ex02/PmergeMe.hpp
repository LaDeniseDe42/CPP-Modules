/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:31:47 by root              #+#    #+#             */
/*   Updated: 2023/12/08 11:39:49 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <climits>

class PmergeMe
{
private:
    std::vector<long long int> _vector;
    std::list<long long int> _list;
    std::vector<long long int>::iterator _vit;
    std::list<long long int>::iterator _lit;

public:
    PmergeMe();//default constructor
    ~PmergeMe();//destructor
    PmergeMe(const PmergeMe &	newPmergeMe); //cpy constructor
    PmergeMe& operator=(const PmergeMe& objectToCopy); //Copy assignment operator

    void    fillVector(long long int nb, char  **argv);
    void    fillList(long long int nb, char **argv);
    void    printVector(int supFive);
    void    printList(int supFive);
    void    mergeVec(int supFive);
    void    mergeLi(int supFive);
    std::vector<long long int>  fordJohnsonVec(std::vector<long long int> tmp, int nbNb);
    std::list<long long int>    fordJohnsonLi(std::list<long long int> tmp, int nbNb);
    int     verifArg(long long int numberOfNumbers, char **argv);
};