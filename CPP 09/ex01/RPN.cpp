/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:22:50 by qdenizar          #+#    #+#             */
/*   Updated: 2023/12/04 16:11:40 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string>

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
    
    static int exitError(int i)
    {
        if (i == 5)
            std::cout << "Error: where is the operator ?" << std::endl;
        if (i == 6)
        {
            std::cout << "Error: cant divide by 0" <<std::endl;
        }
        std::exit(i);
    }

    void    RPN::setNb()
    {
        this->nbResult = 0;
    }

    int    RPN::doOp(char *argv, int i)
    {
        long long int nb = 0;
        std::cout << "ok pour la suite avec argv[i] qui vaut " << argv[i] << std::endl;
                while (argv[i] == ' ')
                    i++;
                if (argv[i] == '+')
                {
                    std::cout << "A.dans le + car argv[i] = " << argv[i] << std::endl;
                    if (_stack.size() < 2)
                        return (2);
                    else
                    {
                        std::cout << "else ?" << std::endl;
                        std::cout << "Size = "<< _stack.size() << " et nbresult = " << nbResult << std::endl;
                        while (_stack.size() >= nbResult +1)
                        {
                            std::cout << "A.nb result +1 au debut de while = " << nbResult +1 << std::endl;
                            std::cout << "A. Et _stack.size() = " << _stack.size() << std::endl;
                            std::cout << "A.stack top = " << _stack.top() << std::endl;
                            nb += _stack.top();
                            std::cout << "A.nb = " << nb << std::endl;
                            if (_stack.size() >= 1)
                                _stack.pop();
                            else if(_stack.size() == 1)
                            {
                                std::cout << "A.stack  avant top = " << _stack.top() << std::endl;
                                _stack.top() = nb;
                                std::cout << "A.stack apres top = " << _stack.top() << std::endl;
                            }
                        }
                        std::cout << "A.tu sors ?" << std::endl;
                        _stack.push(nb);
                        nbResult++;
                        std::cout << "A.nb a la fin = " << nb << std::endl;
                        std::cout << "A. et _stack.top() = " << _stack.top() << std::endl;
                        if (argv[i + 1])
                        {
                            i++;
                            std::cout << "ICI ON REPART SUR PARSE AVEC I = " << i << "ET ARGV[I] = [" << argv[i] << "]" << std::endl;
                            int vre = 0;
                            vre = parse(argv, i);
                            if ( vre != 0)
                            {
                                exitError(vre);
                            }
                            std::cout << argv[i] << " " << argv[i +1] << std::endl;
                        }
                        else
                        {
                            std::cout << "LA???" <<std::endl;
                            return (0);
                        }
                    }
                    if (argv[i +1] == 0)
                    {
                        std::cout << " ou LA???" <<std::endl;
                        return (0);
                    }
                }
                else if (argv[i] == '-')
                {
                    std::cout << "dans le - car argv[i] = " << argv[i] << std::endl;
                    if (_stack.size() < 2)
                        return (2);
                    else
                    {
                        std::cout << "stack top = " << _stack.top() << std::endl;
                        nb = _stack.top();
                        _stack.pop();
                        std::cout << "stack top = " << _stack.top() << std::endl;
                        nb = _stack.top() - nb;
                        _stack.pop();
                        std::cout << "stack top = " << _stack.top() << std::endl;
                        _stack.push(nb);
                        std::cout << "stack top = " << _stack.top() << std::endl;
                    }
                }
                else if (argv[i] == '*')
                {
                    std::cout << "dans le * car argv[i] = " << argv[i] << std::endl;
                    if (_stack.size() < 2)
                        return (2);
                    else
                    {
                        std::cout << "stack top = " << _stack.top() << std::endl;
                        nb = _stack.top();
                        _stack.pop();
                        std::cout << "stack top = " << _stack.top() << std::endl;
                        nb *= _stack.top();
                        _stack.pop();
                        std::cout << "stack top = " << _stack.top() << std::endl;
                        _stack.push(nb);
                        std::cout << "stack top = " << _stack.top() << std::endl;
                    }
                }
                else if (argv[i] == '/')
                {
                    std::cout << "dans le / car argv[i] = " << argv[i] << std::endl;
                    std::cout << "SIze =  " <<  _stack.size() << std::endl; 
                    if (_stack.size() < 2)
                    {
                        
                        return (2);
                    }
                    else
                    {
                        std::stack< long long int> tab;
                        long long int answer = 0;
                        long long int temp = 0;
                        int y = 0;
                        while (_stack.size() > 1)
                        {
                            tab.push(_stack.top());
                            _stack.pop();
                            y++;
                        }
                        while (y != 0)
                        {
                            if (tab.top() == 0)
                                exitError(6);
                            if (temp == 0)
                            {
                                temp++;
                                answer = _stack.top() /  tab.top();
                                if (tab.size() > 1)
                                    tab.pop();
                            }
                            else 
                            {
                                answer /= tab.top();
                                if (tab.size() > 1)
                                    tab.pop();
                            }
                            y--;
                            _stack.top() = answer;
                        }
                    }
                }
                return (0);
    }

    int    RPN::parse(char *argv, int z)
    {
        int i = z;
        int j = 0;
        int test = 1;
        long long int  negativeNb;
        char nbPositive;
        long long int nbP;
        int increment = 0;
        int k = 0;
        int error5 = 0;
        while (argv[k])
            k++;
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
                if (argv[i] == ' ' || (argv[i] >= '0' && argv[i] <= '9') || (argv[i +1] && argv[i] == '-' && (argv[i + 1] >= '0' && argv[i +1] <= '9')))
                {
                    while (argv[i] && (argv[i] != '+' || argv[i] != '*' || argv[i] != '/'))
                    {
                        std::cout << "\033[0;31mi a chaque debut de bouble = \033[0m" << i << " et argv[i] = [" << argv[i] <<"]" << std::endl;
                        if ((argv[i] == '+' || argv[i] == '*' || argv[i] == '/'))
                            break ;
                        if (increment == 0 && argv[i + 1] && argv[i] == '-' && (argv[i + 1] >= '0' && argv[i + 1] <= '9'))
                        {
                            int negSize = i + 1;
                            int negSize2 = 0;
                            std::string temp;
                            std::string temp1 = argv;
                            while (temp1[i +1] && std::isdigit(temp1[i +1]) != 0)
                            {
                                i++;
                                negSize2++;
                                std::cout << "on passe " << negSize2 << " fois dans le while" << std::endl;
                            }
                            temp = temp1.substr(negSize, negSize2);
                            std::cout << "temp = " << temp << std::endl;
                            negativeNb = atoll(temp.c_str());
                            negativeNb = -negativeNb;
                            std::cout << "Negative number = " << negativeNb << std::endl;
                            _stack.push(negativeNb);
                            std::cout << "stack top apres push 1er if = " << _stack.top() << std::endl;
                            negativeNb = 0;
                            i++;
                            i++;
                            j++;
                            increment = 1;
                        }
                        else if (argv[i +1] && argv[i] == '-' && (argv[i + 1] < '0' && argv[i + 1] > '9'))
                        {
                            std::cout << "break car - et pas de chiffre apres" << std::endl;
                            break ;
                        }
                        else if (increment == 0 && argv[i +1] && (argv[i +1] < '0' || argv[i +1] > '9') && (argv[i] >= '0' && argv[i] <= '9'))
                        {
                            std::cout << "je suis dans le premier else if et test = " << test++ << std::endl;
                            nbPositive = argv[i];
                            nbP = std::atoi(&nbPositive);
                            _stack.push(nbP);
                            std::cout << "stack top apres le esle if = " << _stack.top() << std::endl;
                            increment = 2;
                            i++;
                            j++;
                        }
                        std::cout << "stack top apres tout le bordel= " << _stack.top() << std::endl;
                        if (increment == 1 || increment == 2)
                            increment = 0;
                        else
                        {
                            std::cout << k <<std::endl;
                            std::cout << " i = " << i << " et argv[i] = " << argv[i] << "et argv[i +1] = [" << argv[i +1] << "]" << std::endl;
                            if (std::isdigit(argv[i]) != 0 && i + 1 ==  k)
                            {
                                std::cout << "ICI ENCULE ";
                                error5 = 5;
                                break;
                            }
                            else
                                i++;
                        }
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
                std::cout << "tu repasses dans doOp ?" <<std::endl;
                if (doOp(argv, i) == 0)
                {
                    std::cout << "resultat final = " << _stack.top() << std::endl;                    
                    return (0);
                }
            }
        }
        if (error5 == 5 )
            return (5);
        else
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
        else if ( i == 5)
            std::cout << "Error: where is the operator ?" << std::endl;   
    }
