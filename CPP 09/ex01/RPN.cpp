/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:22:50 by qdenizar          #+#    #+#             */
/*   Updated: 2023/12/01 14:11:27 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

    RPN::RPN()
    {
        //std::cout << "default constructor" << std::endl;
    }
    
    //destructor
    RPN::~RPN()
    {
        
    }

     //cpy constructor
    RPN::RPN(const RPN &	newRPN)
    {
        this->_stack = newRPN._stack;
    }

    //Copy assignment operator
    RPN& RPN::operator=(const RPN& objectToCopy)
    {
        if (this == &objectToCopy)
        {
            this->_stack = objectToCopy._stack;
        }
        return (*this);
    }

    // iterator RPN::begin()
    // { 
    //     return std::stack<T>::c.begin();
    // }
    
    // iterator RPN::end()
    // { 
    //     return std::stack<T>::c.end();
    // }

    int    RPN::parse(char *argv)
    {
        int i = 0;
        int j = 0;
        int test = 1;
        char *negativeNb;
        char nbPositive;
        long int nbP;
        long int nb;
        bool increment = false;
        while (argv[i])
        {
            if (argv[i] == ' ' || argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/' || argv[i] == '0' || argv[i] == '1' || argv[i] == '2' || argv[i] == '3' || argv[i] == '4' || argv[i] == '5' || argv[i] == '6' || argv[i] == '7' || argv[i] == '8' || argv[i] == '9')
                ;
            else
            {
                std::cout << "ici car argv[i] = " << argv[i] << " et i = " << i << std::endl;
                return (1);
            }
            if (j == 0)
            {
                std::cout << "dans le 1er if car argv[i] = " << argv[i] << std::endl;
                if (argv[i] == ' ' || (argv[i] >= '0' && argv[i] <= '9') || (argv[i +1] && argv[i] == '-' && (argv[i + 1] >= '0' && argv[i +1] <= '9')))
                {
                    std::cout << "dans le 2ieme if car argv[i] = " << argv[i] << std::endl;
                    while (argv[i] || argv[i] == '+' || argv[i] == '*' || argv[i] == '/')
                    {
                        if (argv[i + 1] && argv[i] == '-' && (argv[i + 1] >= '0' && argv[i + 1] <= '9'))
                        {
                            std::cout << "je suis dans le premier if et test = " << test++ << std::endl;
                            negativeNb[0] = argv[i];
                            negativeNb[1] = argv[i + 1];
                            std::cout << "negativeNb[0] = " << negativeNb[0] << " et de 1 = " << negativeNb[1] << std::endl;
                            std::cout << "negativeNb = " << negativeNb << std::endl;
                            nb = std::atoi(negativeNb);
                            std::cout << "nb = " << nb << std::endl;
                            _stack.push(nb);
                            negativeNb = NULL;
                            nb = 0;
                            i++;
                            j++;
                            increment = true;
                        }
                        else if (argv[i +1] && argv[i] == '-' && (argv[i + 1] < '0' && argv[i + 1] > '9'))
                        {
                            std::cout << "break car - et pas de chiffre apres" << std::endl;
                            break ;
                        }
                        else if (argv[i +1] && (argv[i +1] < '0' || argv[i +1] > '9') && (argv[i] >= '0' && argv[i] <= '9'))
                        {
                            std::cout << "je suis dans le premier else if et test = " << test++ << std::endl;
                            nbPositive = argv[i];
                            nbP = std::atoi(&nbPositive);
                            _stack.push(nbP);
                            increment = true;
                            i++;
                            j++;
                        }
                        std::cout << "stack top = " << _stack.top() << std::endl;
                        if (increment == true)
                            increment = false;
                        else
                            i++;
                    }
                }
                else
                {
                    std::cout << "dans le esle car argv[i] = " << argv[i] << std::endl;
                    return (1);
                }
            }
            std::cout << "j = " << j << " et i = " << i << std::endl;
            if (j < 2)
                return (3);
            else
            {
                std::cout << "ok pour la suite" << std::endl;
            }
        }
        return (0);
    }
    

    void	RPN::print()
    {
        
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
    }
