/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:25:30 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/28 10:58:44 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Use like that: ./bitcoin [file]" << std::endl;
        return (1);
    }
    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier." << std::endl;
        return 1;
    }
    std::map<std::string, long int> stockFile;
    std::string line;
    int lineNumber = 0;
    
    while (std::getline(file, line))
    {
        std::istringstream lineT(line);
        std::string date;
        std::string value;
        if (std::getline(lineT, date, '|') && std::getline(lineT, value, '|'))
        {
            try
            {
            long int valueInt = std::atol(value.c_str());
            stockFile.insert(std::make_pair(date, valueInt));
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << "Error: Invalid value format in line: " << line << std::endl;
            }
        }
        else
            std::cerr << "Error: Invalid line format: " << line << std::endl;
        lineNumber++;
    }
    for (std::map<std::string, long int>::iterator it = stockFile.begin(); it != stockFile.end(); ++it)
    {
        const std::string& date2 = it->first;
        const long int& values2 = it->second;
        std::cout << date2 << "=> " << values2  << " = "<< "A REMPLACER" << std::endl;
    }
    file.close();
   
    return (0);
}