/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:26:29 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/28 14:17:18 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
    public:
    //Orthodox Canonical Form
    BitcoinExchange();//default constructor
    ~BitcoinExchange();//destructor
    BitcoinExchange(const BitcoinExchange &	newBitcoinExchange); //cpy constructor
    BitcoinExchange& operator=(const BitcoinExchange& objectToCopy); //Copy assignment operator

    // void insert(const std::string& date, const T& value) {
    //     stockFile.insert(std::make_pair(date, value));
    // }

    private :
    //std::multimap<std::string, T> stockFile;
    // std::map<std::string, std::string> stockOfFile;
    // std::map<std::string, std::string> stockOfData;
    // std::map<std::string, std::string> stockOfResult;
    
    //int veriFile(std::string fileName);
    // void stockInfoFile(std::string fileName, std::map<std::string, std::string> stockOfFile);
    // void stockInfoData(std::string fileName, std::map<std::string, std::string> stockOfData);
    // void printResult(std::map<std::string, std::string> stockOfFile, std::map<std::string, std::string> stockOfData);
};