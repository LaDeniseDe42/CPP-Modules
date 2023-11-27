/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:26:29 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/27 13:51:07 by qdenizar         ###   ########.fr       */
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

    // std::map<std::string, std::string> stockOfFile;
    // std::map<std::string, std::string> stockOfData;
    // std::map<std::string, std::string> stockOfResult;
    
    //int veriFile(std::string fileName);
    // void stockInfoFile(std::string fileName, std::map<std::string, std::string> stockOfFile);
    // void stockInfoData(std::string fileName, std::map<std::string, std::string> stockOfData);
    // void printResult(std::map<std::string, std::string> stockOfFile, std::map<std::string, std::string> stockOfData);
};