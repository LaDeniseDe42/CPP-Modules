/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:39:24 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/21 14:59:34 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Orthodox Canonical AForm
 
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
 }

 //Copy assignment operator
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& objectToCopy)
{
    std::cout << "\033[0;36mCopy assignment operator called\033[0m " << std::endl;
    if (this != &objectToCopy)
    {

    }
    return (*this);
}
