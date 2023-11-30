/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:26:29 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/30 09:45:12 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
    public:
    //Orthodox Canonical Form
    BitcoinExchange();//default constructor
    BitcoinExchange(std::string fileName_, std::string fileDataName_);
    ~BitcoinExchange();//destructor
    BitcoinExchange(const BitcoinExchange &	newBitcoinExchange); //cpy constructor
    BitcoinExchange& operator=(const BitcoinExchange& objectToCopy); //Copy assignment operator

    // void insert(const std::string& date, const T& value) {
    //     stockFile.insert(std::make_pair(date, value));
    // }
    int fillStockData(BitcoinExchange & stockData);
    void printData(BitcoinExchange & Data);
    int printFile(BitcoinExchange & Data);
    float findAndDoOperation(BitcoinExchange & Data, std::string date, float value);
    bool checkIsValidDate(std::string date);
    std::string getDataName();
    std::string getFileName();

    private :
    std::multimap<std::string, float> stockData;
    std::multimap<std::string, float> stockFile;
    std::string fileName;
    std::string fileDataName;
 
};