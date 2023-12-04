/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:22:46 by qdenizar          #+#    #+#             */
/*   Updated: 2023/12/04 15:08:09 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <cctype>

class RPN
{
private:
    std::stack< long long int> _stack;
    size_t nbResult;
public:
    public:
    //Orthodox Canonical Form
    RPN();//default constructor
    ~RPN();//destructor
    RPN(const RPN &	newRPN); //cpy constructor
    RPN& operator=(const RPN& objectToCopy); //Copy assignment operator
     
    // typedef typename std::stack<T>::container_type::iterator iterator;
    // iterator begin();
    // iterator end();

    int     parse(char *argv, int z);
    int    doOp(char *argv, int i);
    void    print();
    void	error(int i);
    void    setNb();
};