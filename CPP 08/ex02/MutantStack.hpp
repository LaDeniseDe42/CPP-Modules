/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:38:44 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/23 09:44:51 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
        public:
    //Orthodox Canonical Form
    MutantStack();//default constructor
    ~MutantStack();//destructor
    MutantStack(const MutantStack<T> &	newMutantStack); //cpy constructor
    MutantStack<T>& operator=(const MutantStack<T>& objectToCopy); //Copy assignment operator

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return std::stack<T>::c.begin();}
    iterator end() { return std::stack<T>::c.end();}
};

#include "MutantStack.tpp"