/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:35:45 by root              #+#    #+#             */
/*   Updated: 2023/11/16 09:25:53 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//Orthodox Canonical AForm
 
//default constructor
template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0)
{
    std::cout << "\033[0;36mDefault constructor called\033[0m " << std::endl;
}

//destructor
template <typename T>
Array<T>::~Array()
{
    std::cout << "\033[0;31mDestructor called\033[0m " << std::endl;
   delete [] this->_array; 
}

 //cpy constructor
template <typename T>
Array<T>::Array(const Array<T> &	newArray): _array(new T[newArray._size]), _size(newArray._size)
{
    std::cout << "\033[0;36mCopy constructor called\033[0m " << std::endl;
    for (unsigned int i = 0; i < newArray._size; i++)
        this->_array[i] = newArray._array[i];
}

 //Copy assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& objectToCopy)
{
    std::cout << "\033[0;36mCopy assignment operator called\033[0m " << std::endl;
    if (this != &objectToCopy)
    {
        T* tmp = new T[objectToCopy._size];
        for (unsigned long i = 0; i < objectToCopy._size; i++)
            tmp[i] = objectToCopy._array[i];
            
        delete [] this->_array;
        this->_array = tmp;
        this->_size = objectToCopy._size;
    }
    return (*this);
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
    std::cout << "\033[0;36mConstructor with param called\033[0m" << std::endl;
}


template <typename T>
unsigned int Array<T>::size() const
{
    return (this->_size);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= this->_size || index < 0)
    {
        throw std::exception();
    }
    return (this->_array[index]);
}