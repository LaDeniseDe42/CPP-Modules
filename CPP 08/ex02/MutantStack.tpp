/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:39:24 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/23 09:29:00 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
//Orthodox Canonical Form
 
//default constructor
template <typename T>
MutantStack<T>::MutantStack()
{
    std::cout << "\033[0;36mDefault constructor called\033[0m " << std::endl;
}

//destructor
template <typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "\033[0;31mDestructor called\033[0m " << std::endl;
  
}

 //cpy constructor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &	newMutantStack)
{
    std::cout << "\033[0;36mCopy constructor called\033[0m " << std::endl;
    *this = newMutantStack;
 }

 //Copy assignment operator
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& objectToCopy)
{
    std::cout << "\033[0;36mCopy assignment operator called\033[0m " << std::endl;
    if (this != &objectToCopy)
    {
        this->c = objectToCopy.c;
    }
    return (*this);
}
