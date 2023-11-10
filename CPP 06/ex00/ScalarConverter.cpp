/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:31:11 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/10 12:54:00 by qdenizar         ###   ########.fr       */
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
    if (!input[0])
        return false;
    if (input.length() > 11)
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
    int verif = 0;
    while (input[verif])
    {
        if (input[verif] == 'f')
        {
            if (input[verif + 1])
                return false;
            if (input[verif - 1] == '.')
                return false;
        }
        verif++;
    }
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
            if (input[i +1] && ((input[i + 1] >= '0' && input[i + 1] <= '9') || input[i + 1] == 'f')) 
                return true;
            else
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
    int f = 0;
    while (input[f])
    {
        if (input[f] == 'f')
            return false;
        f++;
    }
    size_t start = 0;
    if (input[0] == '+' || input[0] == '-') start = 1;
    bool foundDot = false;
    for (size_t i = start; i < input.length(); ++i)
    {
        if (input[i] == '.')
        {
            if (foundDot)
                return false;
            if (input[i +1] && (input[i + 1] >= '0' && input[i + 1] <= '9')) 
                return true;
            else
                return false;
            foundDot = true;
        }
        else if (!isdigit(input[i]))
            return false;
    }
    return foundDot;
}

static void minff()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
}

static void inff()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
}

static void nanf()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

static void minf()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
}

static void inf()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
}

static void nan()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

static bool needZeroF(std::string f, int isFloat)
{
    if (isFloat == 1)
    {
        int i = 0;
        while (f[i] && f[i] != '.')
            i++;
        int nb_zero = 0;
        while ( f[i] && f[++i] != 'f')
        {
            while (f[i] == '0')
                nb_zero++;
            if (nb_zero > 3)
            {
                if (f[i +1] && f[i + 1] > '5')
                    return false;
                else
                    return true;
            }
            if (f[i] != '0')
            {
                if (nb_zero > 3)
                    return true;
                return false;
            }
        }
        return (true);
    }
    else
    {
        int point = 0;
        while (f[point] && f[point] != '.')
            point++;
        int i = point;
        int nb_zero = 0;
        while (f[i] && f[++i])
        {
            nb_zero++;
            if (nb_zero > 3)
            {
                if (f[i +1] && f[i + 1] > '5')
                    return false;
                else
                    return true;
            }
            if (f[i] != '0')
            {
                if (nb_zero > 3)
                    return true;
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
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    if (needZeroF(input, 0) == true)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (d == i)
    {
        std::cout << std::fixed;
        std::cout.precision(1);
    }
    std::cout << "double: " << d << std::endl;
}

static void convertIntToOtherTypes(const std::string& input)
{
    bool intmax = false;
    long long int inputValue = std::atoll(input.c_str());
    if (inputValue > 2147483647  || inputValue < -2147483648)
       intmax = true;  
    long long int i = inputValue;
    char cara = static_cast<char>(i);
    if (isprint(cara) == false && (!(inputValue >= 0 && inputValue <= 127) || (inputValue > 127)))
        std::cout << "char: impossible" << std::endl;
    else if((inputValue >= 0 && inputValue <= 31) || inputValue == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << cara << "'" << std::endl;
    if (intmax == true)
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
        std::cout << "int: " << i << std::endl;
    float f = static_cast<float>(i);
    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << "float: " << f << "f" << std::endl;
    double d = static_cast<double>(i);
    std::cout << "double: " << d << std::endl;
}


static void convertDoubleToOtherTypes(const std::string& input)
{
    double d = std::strtod(input.c_str(), 0);
    char c = static_cast<char>(d);
    if (isprint(c) == false && (!(d >= 0 && d <= 127) || (d > 127)))
        std::cout << "char: impossible" << std::endl;
    else if((d >= 0 && d <= 31) || d == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);
    std::cout << "int: " << i << std::endl;
    int nb_before_dot = 0;
    int begin_with_zero = 0;
    while (input[begin_with_zero] && input[begin_with_zero] == '0')
        begin_with_zero++;
    while (input[nb_before_dot + begin_with_zero] && input[nb_before_dot + begin_with_zero] != '.')
        nb_before_dot++;
    begin_with_zero++;
    int nb_after_dot = 0;
    int nb_zero_begin_after_dot = 0;
    while (input[nb_before_dot + begin_with_zero + nb_zero_begin_after_dot] && input[nb_before_dot + begin_with_zero + nb_zero_begin_after_dot] == '0')
      nb_zero_begin_after_dot++;
    while (input[nb_before_dot + begin_with_zero + nb_after_dot + nb_zero_begin_after_dot])
        nb_after_dot++;
    if (nb_zero_begin_after_dot >= 1)
    {
        if (nb_before_dot + nb_zero_begin_after_dot >= 6)
        {
            if (nb_before_dot <= 6)
                std::cout << "float: " << f << ".0f" << std::endl;
            else
                std::cout << "float: " << f << "f" << std::endl;
        }
        else
        {
            std::cout << "float: " << f <<"f" << std::endl;
        }
    }
    else
    {
        if (nb_before_dot >= 6)
        {
            if (nb_before_dot <= 6)
                std::cout << "float: " << f << ".0f" << std::endl;
            else
                std::cout << "float: " << f << "f" << std::endl;
        }
        else
        {
            std::cout << "float: " << f  << "f" << std::endl;
        }
    }
    if (d == i)
    {
        std::cout << std::fixed;
        std::cout.precision(1);
    }
        std::cout << "double: " << d << std::endl;
}

static void convertFloatToOtherTypes(const std::string& input)
{
    float f = std::strtof(input.c_str(), NULL);
    int i = static_cast<int>(f);
    char c = static_cast<char>(f);
    if (isprint(c) == false && (!(i >= 0 && i <= 127) || (f > 127)))
        std::cout << "char: impossible" << std::endl;
    else if((i >= 0 && i <= 31) || i == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    double d = static_cast<double>(f);
    std::cout << "int: " << i << std::endl;
    int nb_before_dot = 0;
    int begin_with_zero = 0;
    while (input[begin_with_zero] && input[begin_with_zero] == '0')
        begin_with_zero++;
    while (input[nb_before_dot + begin_with_zero] && input[nb_before_dot + begin_with_zero] != '.')
        nb_before_dot++;
    begin_with_zero++;
    int nb_after_dot = 0;
    int nb_zero_begin_after_dot = 0;
    while (input[nb_before_dot + begin_with_zero + nb_zero_begin_after_dot] && input[nb_before_dot + begin_with_zero + nb_zero_begin_after_dot] == '0')
      nb_zero_begin_after_dot++;
    while (input[nb_before_dot + begin_with_zero + nb_after_dot + nb_zero_begin_after_dot])
        nb_after_dot++;
    if (nb_zero_begin_after_dot >= 1)
    {
        if (nb_before_dot + nb_zero_begin_after_dot >= 6)
        {
            if (nb_before_dot <= 6)
                std::cout << "float: " << f << "f" << std::endl;
            else
                std::cout << "float: " << f << "f" << std::endl;
        }
        else
        {
            std::cout << "float: " << f <<"f" << std::endl;
        }
    }
    else
    {
        if (nb_before_dot >= 6)
        {
            if (nb_before_dot <= 6)
                std::cout << "float: " << f << ".0f" << std::endl;
            else
                std::cout << "float: " << f << "f" << std::endl;
        }
        else
        {
            std::cout << "float: " << f  << "f" << std::endl;
        }
    }
    if (d == i)
    {
        std::cout << std::fixed;
        std::cout.precision(1);
    }
        std::cout << "double: " << d << std::endl;
}


void ScalarConverter::convert(const std::string& stringToConvert)
{
    if (isAChar(stringToConvert))
    {
        //std::cout << "is char" << std::endl;
        convertCharToOtherTypes(stringToConvert);
    }
    else if (isAInt(stringToConvert))
    {
        //std::cout << "is int" << std::endl;
        convertIntToOtherTypes(stringToConvert);
    }
    else if (isADouble(stringToConvert))
    {
        //std::cout << "is double" << std::endl;
        convertDoubleToOtherTypes(stringToConvert);
    }
    else if (isAFloat(stringToConvert))
    {
        //std::cout << "is float" << std::endl;
        convertFloatToOtherTypes(stringToConvert);
    }
    else if (stringToConvert == "-inff")
        minff();
    else if (stringToConvert == "+inff")
        inff();
    else if (stringToConvert == "nanf")
        nanf();
    else if (stringToConvert == "-inf")
        minf();
    else if (stringToConvert == "+inf")
        inf();
    else if (stringToConvert == "nan")
        nan();
    else
        std::cout << "Invalid stringToConvert." << std::endl;
}


//destructor
ScalarConverter::~ScalarConverter()
{
	//std::cout << "Hey you i'm \033[36mScalarConverter\033[0m destructor" << std::endl;
}