/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:29:20 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/03 13:52:21 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class ScalarConverter
{
    private:
        //Orthodox Canonical ScalarConverter
        ScalarConverter();//default constructor
        ~ScalarConverter();//destructor
        ScalarConverter(const ScalarConverter&	newScalarConverter); //cpy constructor
        ScalarConverter& operator=(ScalarConverter const & objectToCopy); //Copy assignment operator
        ScalarConverter(std::string stringToConvert); //constructor with string
    
        std::string stringToConvert;
    
    public:
        static void convert(const std::string& stringToConvert);
        
};


