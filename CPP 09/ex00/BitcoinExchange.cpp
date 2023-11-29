/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:26:13 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/29 12:39:55 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//Orthodox Canonical Form
    
//default constructor
BitcoinExchange::BitcoinExchange() : fileName(NULL), fileDataName(NULL)
{
}

//construcor with all
BitcoinExchange::BitcoinExchange(std::string fileName_, std::string fileDataName_) : fileName(fileName_), fileDataName(fileDataName_)
{
}

    
//destructor
BitcoinExchange::~BitcoinExchange()
{
        
}
    
//cpy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &	newBitcoinExchange) 
{
    (void)newBitcoinExchange;
    
    this->fileName = newBitcoinExchange.fileName;
    this->fileDataName = newBitcoinExchange.fileDataName;
}

    
//Copy assignment operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& objectToCopy)
{
    if (this != &objectToCopy)
    {
        this->fileName = objectToCopy.fileName;
        this->fileDataName = objectToCopy.fileDataName;
    }
        return (*this);
}

//FUNCTIONS


std::string BitcoinExchange::getDataName()
{
    return (this->fileDataName);
}

std::string BitcoinExchange::getFileName()
{
    return (this->fileName);
}

int BitcoinExchange::fillStockData(BitcoinExchange & Data)
{
    std::ifstream dataFile(Data.getDataName().c_str());
    if (!dataFile.is_open())
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier." << std::endl;
        return 1;
    }
    std::string dataLine;
    int dataLineNumber = 0;
    std::getline(dataFile, dataLine);
    while (std::getline(dataFile, dataLine))
    {
        std::istringstream lineD(dataLine);
        std::string dataDate;
        std::string dataValue;
        if (std::getline(lineD, dataDate, ',') && std::getline(lineD, dataValue, ','))
        {
            char *returnOfTof2;
            float valuefloatData = std::strtof(dataValue.c_str(), &returnOfTof2);
            stockData.insert(std::make_pair(dataDate, valuefloatData));
        }
        else
        {
            //std::cerr << "Error: Invalid dataLine format: " << dataLine << std::endl;
            stockData.insert(std::make_pair("Error: Invalid dataLine format: ", 666));
        }
        dataLineNumber++;
    }
    dataFile.close();
    return (0);
}

void    BitcoinExchange::printData(BitcoinExchange & Data)
{
    for (std::map<std::string, float>::iterator it = Data.stockData.begin(); it != Data.stockData.end(); ++it)
    {
        const std::string& date2 = it->first;
        const float& values2 = it->second;
        std::cout << date2 << " => " << values2  << std::endl;
    }
}

int BitcoinExchange::printFile(BitcoinExchange & Data)
{

    std::ifstream file(Data.getFileName().c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    std::string line;
    double lineNumber = 0;
    
    while (std::getline(file, line))
    {
        std::istringstream lineT(line);
        std::string date;
        std::string value;
        if (std::getline(lineT, date, '|') && std::getline(lineT, value, '|'))
        {
            char *returnOfTof;
            float valuefloat = std::strtof(value.c_str(), &returnOfTof);
            if (value.length() > 7 || valuefloat >= 1000)
            {
                Data.stockFile.insert(std::make_pair("Error: too large a number", 666));
                std::cout <<"Error: too large a number"<< std::endl;
            }
            else if (valuefloat <= 0 && lineNumber != 0)
            {
                Data.stockFile.insert(std::make_pair("Error: not a positive number.", 666));
                std::cout << "Error: not a positive number."<< std::endl;
            }
            else
            {
                Data.stockFile.insert(std::make_pair(date, valuefloat));
                if (lineNumber != 0)
                    std::cout << date << "=> " << value  << " = "<< Data.findAndDoOperation(Data, date, valuefloat)<<  std::endl;
            }
        }
        else
        {
            Data.stockFile.insert(std::make_pair("Error: bad input =>  " + line, lineNumber));
            if (lineNumber != 0)
                std::cout << "Error: bad input =>  " << date << std::endl;
        }
        lineNumber++;
    }
    file.close();
    return (0);
}

float BitcoinExchange::findAndDoOperation(BitcoinExchange & Data, std::string date, float value)
{
    std::multimap<std::string, float>::iterator it ;
    it = Data.stockData.find(date);
    if (it != Data.stockData.end())
    {
        const float& values2 = it->second * value;
        return (values2);
    }
    else
    {
        it = Data.stockData.upper_bound(date);
        it--;
        const float& values2 = it->second * value;
        return (values2);
    }
    
}