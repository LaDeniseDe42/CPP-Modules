/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:38:44 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/21 15:56:23 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typedef T>
class MutantStack : public std::stack
{
        public:
    //Orthodox Canonical Form
    MutantStack();//default constructor
    ~MutantStack();//destructor
    MutantStack(const MutantStack<T> &	newMutantStack); //cpy constructor
    MutantStack<T>& operator=(const MutantStack<T>& objectToCopy); //Copy assignment operator

        private:
    
}