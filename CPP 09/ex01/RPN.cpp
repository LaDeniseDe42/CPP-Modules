/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:22:50 by qdenizar          #+#    #+#             */
/*   Updated: 2023/12/06 11:22:54 by root             ###   ########.fr       */
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
        int i = 0;
	    for (std::string::const_iterator it = argv.begin(); it != argv.end(); it++)
        {
		    if (*it == ' ')
			    continue;
		    if (*it == '-' || *it == '+' || *it == '/' || *it == '*')
            {
			    if (_stack.size() >= 2)
                {
				    i = doOp(*it);
                    if (i != 0)
                    {
                        error(i);
                        return (1);
                    }
                }
			    continue;
		    }
		    _stack.push(*it - 48);
	    }
	    if (_stack.size() > 1)
		    return (8);
	    std::cout << "\033[0;36mResult: \033[1m" << _stack.top() << "\033[0m" << std::endl;
        return (0);
    }
    
    int    RPN::doOp(const char ope)
    {
        int topNumber = _stack.top();
	    _stack.pop();
	    int firstToBePush = _stack.top();
	    _stack.pop();
	    switch(ope) {
		case '+':
        {
			_stack.push(firstToBePush + topNumber);
			break;    
        }
		case '-':
        {
			_stack.push(firstToBePush - topNumber);
			break;
        }
		case '*':
        {
			_stack.push(firstToBePush * topNumber);
			break;
        }
		case '/':
        {
            if (topNumber == 0)
                return (4);
			_stack.push(firstToBePush / topNumber);
			break;   
        }
	}
    return (0);
    }

    int     RPN::parse(const std::string argv)
    {
        int compNumber = 0;
        int compOperator = 0;
        if (argv.length() == 0)
            return (3);
        for (int i = 0; i < int(argv.length()); i++)
        {
            if (argv[0] == ' ')
                return (7);
            if (argv[i] == '-' || argv[i] == '+' || argv[i] == '/' || argv[i] == '*' || argv[i] == ' ' || (argv[i] >= '0' && argv[i] <= '9'))
                ;
            else
			    return (1);
		    if (i % 2 == 1)
            {
			    if (argv[i] != ' ')
				    return (7);
                if (argv[i] == ' ' && argv[i + 1] == ' ')
                    return (7);
		    }
            if (argv[i] >= '0' && argv[i] <= '9')
                compNumber++;
            if (argv[i] == '-' || argv[i] == '+' || argv[i] == '/' || argv[i] == '*')
                compOperator++;
            if (argv[i] >= '0' && argv[i] <= '9' && argv[i + 1] >= '0' && argv[i + 1] <= '9')
                return (6);
            if (i == 3 && compNumber != 2)
                return (2);
	    }
        if (compNumber - compOperator != 1)
        {
            return (8);
        }
	    return (0);
    }
    
    void	RPN::error(int i)
    {
        if (i == 1)
            std::cout << "\033[0;31mError: invalid character\033[0m" << std::endl;
        else if (i == 2)
            std::cout << "\033[0;31mError: need at least two numbers at the begining\033[0m" << std::endl;
        else if (i == 3)
            std::cout << "\033[0;31mError: not enaf elements\033[0m" << std::endl;
        else if (i == 4)
            std::cout << "\033[0;31mError: division by zero\033[0m" << std::endl;
        else if ( i == 5)
            std::cout << "\033[0;31mError: where is the operator ?\033[0m" << std::endl;
        else if (i == 6)
            std::cout << "\033[0;31mError: can't manage number > 9\033[0m" <<std::endl;
        else if (i == 7)
            std::cout << "\033[0;31mError: please take care put one space between things\033[0m" <<std::endl;
        else if (i == 8)
            std::cout << "\033[0;31mError: number or operator walking alone in the string\033[0m" <<std::endl;
        else if (i == 9)
            std::cout << "\033[0;31mError: Please don't use SPACE at first character\033[0m" <<std::endl;
    }
