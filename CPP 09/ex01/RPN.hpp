/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:22:46 by qdenizar          #+#    #+#             */
/*   Updated: 2023/12/05 15:43:38 by qdenizar         ###   ########.fr       */
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
    std::stack<long long int> _stack;
    size_t nbResult;
public:
    public:
    //Orthodox Canonical Form
    RPN();//default constructor
    ~RPN();//destructor
    RPN(const RPN &	newRPN); //cpy constructor
    RPN& operator=(const RPN& objectToCopy); //Copy assignment operator

    int     parse(const std::string argv);
    int     doOp(const char ope);
    int     rpn(std::string argv);
    void	error(int i);
};