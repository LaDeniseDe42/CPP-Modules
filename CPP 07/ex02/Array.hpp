/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:35:42 by root              #+#    #+#             */
/*   Updated: 2023/11/15 14:34:33 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
    public:
    //Orthodox Canonical AForm
    Array();//default constructor
    ~Array();//destructor
    Array(const Array<T> &	newArray); //cpy constructor
    Array<T>& operator=(const Array<T>& objectToCopy); //Copy assignment operator

    Array(unsigned int n); //constructor with param

    unsigned int size() const;
    T& operator[](unsigned int index);
    
    private:
        T *_array;
        unsigned int _size;
};

#include "Array.tpp"