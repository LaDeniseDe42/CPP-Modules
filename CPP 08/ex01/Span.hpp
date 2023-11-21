/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:23:15 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/21 12:27:32 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>


class Span
{
    private:
        unsigned int _n;
        std::vector<int> _stockNValues;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &src);
        ~Span();
        Span &operator=(const Span &src);
        
        void addNumber(unsigned int valueToAdd);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        void printValue();
        
};