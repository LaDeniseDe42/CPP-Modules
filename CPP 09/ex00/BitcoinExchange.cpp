/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:26:13 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/28 14:17:23 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//Orthodox Canonical Form
    
//default constructor
BitcoinExchange::BitcoinExchange()
{
    // stockOfData = NULL;
    // stockOfFile = NULL;
    // stockOfResult = NULL; 
    //stockFile = NULL;
}

    
//destructor
BitcoinExchange::~BitcoinExchange()
{
        
}
    
//cpy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &	newBitcoinExchange) 
{
    (void)newBitcoinExchange;
    // this->stockOfData = newBitcoinExchange.stockOfData;
    // this->stockOfFile = newBitcoinExchange.stockOfFile;
    // this->stockOfResult = newBitcoinExchange.stockOfResult;
}

    
//Copy assignment operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& objectToCopy)
{
    if (this != &objectToCopy)
    {
        // this->stockOfData = objectToCopy.stockOfData;
        // this->stockOfFile = objectToCopy.stockOfFile;
        // this->stockOfResult = objectToCopy.stockOfResult;
    }
        return (*this);
}

//FUNCTIONS

// int veriFile(std::string fileName)
// {
//     std::string line;
//     int i = 0;
//     std::istream file(fileName);
//     if (!file.is_open())
//     {
//         std::cout << "Error with file.." << std::endl;
//         return (1);
//     }
//     while (std::getline(file, line))
//     {
//         std::cout << line << std::endl; 
//     }
//     return (0);
// }

// void stockInfoFile(std::string fileName, std::map<std::string, std::string> stockOfFile)
// {
    
// }


// void stockInfoData(std::string fileName, std::map<std::string, std::string> stockOfData)
// {
    
// }


// void printResult(std::map<std::string, std::string> stockOfFile, std::map<std::string, std::string> stockOfData)
// {

    
// }