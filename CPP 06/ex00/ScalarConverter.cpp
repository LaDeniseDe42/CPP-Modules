/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:31:11 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/06 15:35:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//CONSTRUCTEURS

//default
ScalarConverter::ScalarConverter()
{
	//std::cout << "\033[33mScalarConverter default constructor called \033[0m " << std::endl;
}

//cpy constructor
ScalarConverter::ScalarConverter(const ScalarConverter&	newScalarConverter)
{ 
	//std::cout << "\033[33mScalarConverter Copy constructor called\033[0m " << std::endl;
	*this = newScalarConverter;
}

//constructor with string
ScalarConverter::ScalarConverter(std::string stringToConvert)
{
   // std::cout << "\033[33mScalarConverter constructor with string called\033[0m " << std::endl;
    this->stringToConvert = stringToConvert;

}

//Copy assignment operator
ScalarConverter& ScalarConverter::operator=(ScalarConverter const & objectToCopy)
{
	//std::cout << "\033[33mScalarConverter Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
        
	}
	return (*this);
}


//Functions

static bool isAChar(const std::string& input)
{
    if (std::isprint(input[0]) && !std::isdigit(input[0]) && input.length() == 1)
        return true;
    else
        return false;
}

static bool isAInt(const std::string& input)
{
    size_t start = 0;
    if (input[0] == '+' || input[0] == '-') start = 1;
    for (size_t i = start; i < input.length(); ++i)
    {
        if (!std::isdigit(input[i]))
            return false;
    }
    return true;
}

static bool isAFloat(const std::string& input)
{
    size_t start = 0;
    if (input[0] == '+' || input[0] == '-')
        start = 1;
    bool foundDot = false;
    for (size_t i = start; i < input.length(); ++i)
    {
        if (input[i] == '.')
        {
            if (foundDot)
                return false;
            foundDot = true;
        }
        else if (!isdigit(input[i]) && input[i] != 'f')
            return false;
    }
    return foundDot;
}

static bool isADouble(const std::string& input)
{
    size_t start = 0;
    if (input[0] == '+' || input[0] == '-') start = 1;
    bool foundDot = false;
    for (size_t i = start; i < input.length(); ++i)
    {
        if (input[i] == '.')
        {
            if (foundDot) return false;
            foundDot = true;
        }
        else if (!isdigit(input[i]))
            return false;
    }
    return foundDot;
}

static bool needZeroF(std::string f, int isFloat)
{
    if (isFloat == 1)
    {
    int i = 0;
    while (f[i] != '.')
        i++;
    while (f[++i] != 'f')
    {
        if (f[i] != '0')
        {
            return false;
        }
    }
    return (true);
    }
    else{
        int i = 0;
    while (f[i] != '.')
        i++;
    while (f[++i])
    {
        if (f[i] != '0')
        {
            return false;
        }
    }
    return (true);
    }    
}

static void convertCharToOtherTypes(const std::string& input)
{
    char c = input[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
     if (needZeroF(input, 0) == true)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;
}

static void convertIntToOtherTypes(const std::string& input)
{
    bool intmax = false;
    int inputValue = std::atoi(input.c_str());
    std::cout << "inputValue = " << inputValue << std::endl;
    if (inputValue == 2147483647  && inputValue == -2147483648)
       intmax = true;
    int i = inputValue;
    char cara = static_cast<char>(i);
    if (isprint(cara) == false)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: " << cara << std::endl;
    if (intmax == true)
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
        std::cout << "int: " << i << std::endl;
    float f = static_cast<float>(i);  
    if (needZeroF(input,0) == true)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    
    double d = static_cast<double>(i);
    std::cout << "double: " << d << ".0" << std::endl;
}


static void convertDoubleToOtherTypes(const std::string& input)
{
    double d = std::atof(input.c_str());
    char c = static_cast<char>(d);
    if (isprint(c) == false)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: " << c << std::endl;
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);
    std::cout << "int: " << i << std::endl;
    if (needZeroF(input,0) == true)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

static void convertFloatToOtherTypes(const std::string& input)
{
    float f = std::strtof(input.c_str(), NULL);
    std::cout << "f = " << f << std::endl;
    int i = static_cast<int>(f);
    char c = static_cast<char>(f);
    if (isprint(c) == false )
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: " << c << std::endl;
    double d = static_cast<double>(f);
    std::cout << "int: " << i << std::endl;
    if (needZeroF(input,1) == true)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}


void ScalarConverter::convert(const std::string& stringToConvert)
{
    if (isAChar(stringToConvert))
    {
        std::cout << "is char" << std::endl;
        convertCharToOtherTypes(stringToConvert);
    }
    else if (isAInt(stringToConvert))
    {
        std::cout << "is int" << std::endl;
        convertIntToOtherTypes(stringToConvert);
    }
    else if (isADouble(stringToConvert))
    {
        std::cout << "is double" << std::endl;
        convertDoubleToOtherTypes(stringToConvert);
    }
    else if (isAFloat(stringToConvert))
    {
        std::cout << "is float" << std::endl;
        convertFloatToOtherTypes(stringToConvert);
    }
    else
        std::cout << "Invalid stringToConvert." << std::endl;
}


//destructor
ScalarConverter::~ScalarConverter()
{
	//std::cout << "Hey you i'm \033[36mScalarConverter\033[0m destructor" << std::endl;
}