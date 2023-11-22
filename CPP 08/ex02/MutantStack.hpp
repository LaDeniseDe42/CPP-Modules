/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:38:44 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/22 16:34:52 by qdenizar         ###   ########.fr       */
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
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    iterator begin() { return std::stack<T>::c.begin();}
    iterator end() { return std::stack<T>::c.end();}
    reverse_iterator rend() { return std::stack<T>::c.rend();}
    reverse_iterator rbegin() { return std::stack<T>::c.rbegin();}
    //MutantStack& operator=(const MutantStack & rhs){ std::stack<T>::operator=(rhs);}
};

#include "MutantStack.tpp"