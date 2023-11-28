/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:25:30 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/28 16:31:02 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    //first file
    std::multimap<std::string, float> stockFile;
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
                stockFile.insert(std::make_pair("Error: too large a number", 666));
            else if (value.find('-') == 0 || valuefloat <= 0)
                stockFile.insert(std::make_pair("Error: not a positive number.", 666));
            else
                stockFile.insert(std::make_pair(date, valuefloat));
        }
        else
        {
            stockFile.insert(std::make_pair("Error: bad input =>  " + line, lineNumber));
        }
        lineNumber++;
    }
    
    //data.csv
    std::ifstream dataFile("data.csv");
    if (!dataFile.is_open())
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier." << std::endl;
        return 1;
    }
    std::multimap<std::string, float> stockData;
    std::string dataLine;
    int dataLineNumber = 0;

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
            std::cerr << "Error: Invalid dataLine format: " << dataLine << std::endl;
        dataLineNumber++;
    }

    for (std::map<std::string, float>::iterator it = stockFile.begin(); it != stockFile.end(); ++it)
    {
        const std::string& date2 = it->first;
        const float& values2 = it->second;
        if (date2.find("Error: bad input") == 0)
            std::cout << date2 << std::endl;
        else if (date2.find("Error: too large") == 0)
            std::cout <<date2 << std::endl;
        else if (date2.find("Error: not a positive") == 0)
            std::cout <<date2 << std::endl;
        else
            std::cout << date2 << "=> " << values2  << " = "<< "A REMPLACER" << std::endl;
    }

    

    //Pour print Data
    // for (std::map<std::string, float>::iterator it = stockData.begin(); it != stockData.end(); ++it)
    // {
    //     const std::string& date2 = it->first;
    //     const float& values2 = it->second;
    //     std::cout << date2 << " => " << values2  << std::endl;
    // }
    
    file.close();
    dataFile.close();
   
    return (0);
}