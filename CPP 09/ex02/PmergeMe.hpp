/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:31:47 by root              #+#    #+#             */
/*   Updated: 2023/12/06 15:06:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

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
    void    printVector();
    void    printList();
    void    mergeVec();
    void    mergeLi();
};