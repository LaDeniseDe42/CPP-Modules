/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:26:13 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/30 13:16:41 by qdenizar         ###   ########.fr       */
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
    //(void)newBitcoinExchange;
    
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
            if (valuefloat <= 0 && lineNumber != 0)
            {
                Data.stockFile.insert(std::make_pair("Error: not a positive number.", 666));
                std::cout << "Error: not a positive number."<< std::endl;
            }
            else if (value.length() > 7 || valuefloat >= 1000)
            {
                Data.stockFile.insert(std::make_pair("Error: too large a number", 666));
                std::cout <<"Error: too large a number"<< std::endl;
            }
            else
            {
                Data.stockFile.insert(std::make_pair(date, valuefloat));
                if (lineNumber != 0)
                {
                    if (Data.checkIsValidDate(date) == false)
                        std::cout << "Error: invalid date  => " << date << std::endl;
                    else
                        std::cout << date << "=> " << value  << " = "<< Data.findAndDoOperation(Data, date, valuefloat)<<  std::endl;    
                }
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
        if (it == Data.stockData.begin())
            it++;
        else
            it--;
        const float& values2 = it->second * value;
        return (values2);
    }  
}

bool BitcoinExchange::checkIsValidDate(std::string date)
{
    if (date.length() != 11)
        return (false);
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return (false);
        }
        else
        {
            if (!std::isdigit(date[i]))
                return (false);
        }
    }
    //std::cout << "date = " << date << std::endl;
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    //std::cout << " std::string y/m/d = " << year << "-" << month << "-" << day << std::endl;
    int yearI = std::atoi(year.c_str()); 
    int monthI = std::atoi(month.c_str());
    int dayI = std::atoi(day.c_str());
    int bissextile = 666;
    if (monthI > 12)
        return (false);
    if (year.length() > 4 || month.length() > 2 || day.length() > 2)
        return (false);
    if ((yearI % 4 == 0 && yearI % 100 != 0) || (yearI % 400 == 0))
    {
        bissextile = 0;
    }
    else
        bissextile = 1;
    
    switch (monthI)
    {
        case 1:
        {
            if (dayI <= 0 || dayI > 31)
                return(false);
        }
        case 2:
        {
            if (bissextile == 0)
            {
                if ((dayI <= 0 || dayI > 29))
                    return(false);  
            }
            else if (bissextile == 1)
            {
                if (dayI <= 0 || dayI > 28)
                    return(false); 
            }
        }
        case 3:
        {
            if (dayI <= 0 || dayI > 31)
                return(false);
        }
        case 4:
        {
            if (dayI <= 0 || dayI > 30)
                return(false);
        }
        case 5:
        {
            if (dayI <= 0 || dayI > 31)
                return(false);
        }
        case 6:
        {
            if (dayI <= 0 || dayI > 30)
                return(false);
        }
        case 7:
        {
            if (dayI <= 0 || dayI > 31)
                return(false);
        }
        case 8:
        {
            if (dayI <= 0 || dayI > 31)
                return(false); 
        }
        case 9:
        {
            if (dayI <= 0 || dayI > 30)
                return(false); 
        }
        case 10:
        {
            if (dayI <= 0 || dayI > 31)
                return(false);  
        }
        case 11:
        {
            if (dayI <= 0 || dayI > 30)
                return(false);  
        }
        case 12:
        {
            if (dayI <= 0 || dayI > 31)
                return(false); 
        }
    } 
    return (true);
}