/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:31:11 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/03 15:45:13 by qdenizar         ###   ########.fr       */
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
        if (input.empty())
            return false;
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
        if (input.empty())
            return false;
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
        if (input.empty())
            return false;
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

void ScalarConverter::convert(const std::string& stringToConvert)
{
    if (isAChar(stringToConvert))
        std::cout << "is char" << std::endl;
    else if (isAInt(stringToConvert))
        std::cout << "is int" << std::endl;
    else if (isADouble(stringToConvert))
        std::cout << "is double" << std::endl;
    else if (isAFloat(stringToConvert))
        std::cout << "is float" << std::endl;
    else
        std::cout << "Invalid stringToConvert." << std::endl;
}


//destructor
ScalarConverter::~ScalarConverter()
{
	//std::cout << "Hey you i'm \033[36mScalarConverter\033[0m destructor" << std::endl;
}