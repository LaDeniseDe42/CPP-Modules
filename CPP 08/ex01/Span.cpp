/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:23:13 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/21 12:40:21 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

    
    Span::Span() : _n(0), _stockNValues()
    {
        
    }
    
    Span::Span(unsigned int n) : _n(n), _stockNValues()
    {
        
    }

    Span::Span(const Span &src)
    {
        this->_n = src._n;
        this->_stockNValues = src._stockNValues;
    }
    
    Span::~Span()
    {
        
    }
    
    Span &Span::operator=(const Span &src)
    {
        if (this != &src)
        {
            this->_n = src._n;
            this->_stockNValues = src._stockNValues;
        }
        return (*this);
    }


    void Span::addNumber(unsigned int valueToAdd)
    {
        if (_stockNValues.size() == _n)
            throw std::logic_error("No place left to add number");
        _stockNValues.push_back(valueToAdd);
    }
    
    unsigned int Span::shortestSpan() const
    {
        if (_stockNValues.size() < 2)
            throw std::logic_error("Not enaf numbers to find span");
        std::vector<int> sortedVector = _stockNValues;
        std::sort(sortedVector.begin(), sortedVector.end());

        int shortestS = sortedVector[1] - sortedVector[0];
        for (unsigned int i = 2; i < sortedVector.size(); i++)
        {
            int TheSpan = sortedVector[i] - sortedVector[i -1];
            if (TheSpan < shortestS)
                shortestS = TheSpan;
        }
        return (shortestS);

    }
    
    unsigned int Span::longestSpan() const
    {
        if (_stockNValues.size() < 2)
            throw std::logic_error("Not enaf numbers to find span");
        std::vector<int> sortedVector = _stockNValues;
        std::sort(sortedVector.begin(), sortedVector.end());
        int maxMinusMin = sortedVector.back() - sortedVector.front();
        return (maxMinusMin); 
    }


    template <typename T>
    static void print_tab(T me)
    {
        std::cout << "\033[0;32m" << me << " ; \033[0m";
    }

    void Span::printValue()
    {
        std::for_each(_stockNValues.begin(), _stockNValues.end(), print_tab<int>);
        std:: cout << std::endl;
    }
