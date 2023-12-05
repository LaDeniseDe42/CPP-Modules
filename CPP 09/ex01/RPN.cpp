/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:22:50 by qdenizar          #+#    #+#             */
/*   Updated: 2023/12/05 15:25:44 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string>

    RPN::RPN()
    {
        //std::cout << "default constructor" << std::endl;
        this->nbResult = 0;
    }
    
    //destructor
    RPN::~RPN()
    {
        
    }

     //cpy constructor
    RPN::RPN(const RPN &	newRPN)
    {
        this->_stack = newRPN._stack;
        this->nbResult = 0;
    }

    //Copy assignment operator
    RPN& RPN::operator=(const RPN& objectToCopy)
    {
        if (this == &objectToCopy)
        {
            this->_stack = objectToCopy._stack;
            this->nbResult = objectToCopy.nbResult;
        }
        return (*this);
    }

    int     RPN::rpn(std::string argv)
    {
	for (std::string::const_iterator it = argv.begin(); it != argv.end(); it++) {
		if (*it == ' ')
			continue;
		if (*it == '-' || *it == '+' || *it == '/' || *it == '*') {
			if (_stack.size() >= 2)
				doOp(*it);
			continue;
		}
		_stack.push(*it - 48);
	}
	if (_stack.size() > 1) {
		return (8);
	}
	std::cout << "Result: " << _stack.top() << std::endl;
    return (0);
    }
    
    int    RPN::doOp(const char ope)
    {
        int a = _stack.top();
	    _stack.pop();
	    int b = _stack.top();
	    _stack.pop();
	    switch(ope) {
		case '+':
			_stack.push(b + a);
			break;
		case '-':
			_stack.push(b - a);
			break;
		case '*':
			_stack.push(b * a);
			break;
		case '/':
			_stack.push(b / a);
			break;
	}
    return (0);
    }

    int     RPN::parse(const std::string argv)
    {
        for (int i = 0; i < int(argv.length()); i++)
        {
		if (i % 2 == 1)
        {
			if (argv[i] != ' ')
				return (7);
		}
        else if (argv[i] != '-' && argv[i] != '+' && argv[i] != '/' && argv[i] != '*' && !isdigit(argv[i]))
			return (1);
	}
	return 0;
    }
    
    void	RPN::error(int i)
    {
        if (i == 1)
            std::cout << "Error: invalid character" << std::endl;
        else if (i == 2)
            std::cout << "Error: stack is empty" << std::endl;
        else if (i == 3)
            std::cout << "Error: not enaf elements" << std::endl;
        else if (i == 4)
            std::cout << "Error: division by zero" << std::endl;
        else if ( i == 5)
            std::cout << "Error: where is the operator ?" << std::endl;
        else if (i == 6)
            std::cout << "Error: can't manage positif number" <<std::endl;
        else if (i == 7)
            std::cout << "Error: please take care put space between " <<std::endl;
        else if (i == 8)
            std::cout << "Error: number walking alone in the string" <<std::endl;
    }
