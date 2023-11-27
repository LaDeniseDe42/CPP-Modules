/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:25:30 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/27 17:01:36 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./bitcoin [file]" << std::endl;
        return (1);
    }
    BitcoinExchange exchange;
    
    std::string line;
    int floatOrNot = 0;
    int i = 0;
    int j = 0;
    int err = 0;
    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Error: cant open file.." << std::endl;
        return (1);
    }
    while (std::getline(file, line))
    {
        if ( i == 0)
        {
            if (line != "date | value")
            {
                err = 1;
                std::cerr << "Error with file content.." << std::endl;
                return (1);
            }
            std::getline(file, line);
        }
        if (i != 0)
        {
            std::string templine = line;
            j = 0;
            //int test = templine.length();
            // std::cout << " test = " << test << " et i = " <<  i << std::endl;
            // std::cout << "line =  " << templine << " et j = " << j << std::endl;
            if (templine.length() <= 12 )
            {
                if (err == 0)
                {
                std::cout << templine[j] << "  => ";
                std::cerr << "Error: incomplete line" << std::endl;
                err = 1;
                    
                }
                //std::getline(file, line);

            }
            while (j != 3)
            {
                if (std::isdigit(templine[j]) == 0)
                {
                    if (err == 0)
                    {
                    std::cout << templine[j] << "  => ";
                    std::cerr << "Error with Year.." << std::endl;
                    err = 1;
                    //std::getline(file, line);
                    }
    
                }
                j++;
            }
            if (templine[j] != '-')
            {
                if (err == 0)
                {
                std::cout << templine[j] << "  => ";
                std::cerr << "Error with " << templine[j] << ".." << std::endl;
                err = 1;
                //std::getline(file, line);
                }

            }
            j++;
            if (std::isdigit(templine[j]) == 0 || std::isdigit(templine[j + 1]) == 0)
            {
                if (err == 0)
                {
                std::cout << templine[j] << "  => ";
                std::cerr << "Error with Month.." << std::endl;
                err = 1;
                //std::getline(file, line);
                }

            }
            j+= 2;
            if (templine[j] != '-')
            {
                if (err == 0)
                {
                std::cout << templine[j] << "  => ";
                std::cerr << "Error with " << templine[j] << ".." << std::endl;
                err = 1;
                //std::getline(file, line);
                }

            }
            j++;
            if (std::isdigit(templine[j]) == 0 || std::isdigit(templine[j + 1]) == 0)
            {
                if (err == 0)
                {
                std::cout << templine[j] << "  => ";
                std::cerr << "Error with day.." << std::endl;
                err = 1;
                }
                //std::getline(file, line);

            }
            j+= 2;
            if (templine[j] == '\0' || templine[j] != ' ' || templine[j + 1] != '|' || templine[j + 2] != ' ')
            {
                if (err == 0)
                {
                std::cout << templine[j] << "  => ";
                std::cerr << "Error with " << templine[i] << ".." << std::endl;
                err = 1;
                }
                //std::getline(file, line);

            }
            j+= 3;
            char a;
            std::string svalue;
            while (templine[j])
            {
                a = templine[j];
                svalue += a;
                if (std::isdigit(templine[j]) == 0)
                {
                    if (templine[j] == '.' || templine[j] == '-' || templine[j] == '+')
                    {
                        floatOrNot = 0;
                        if (templine[j] == '.')
                            floatOrNot = 1;
                        if (templine[j +1] && (templine[j+ 1] == '.' || templine[j +1] == '-' || templine[j +1] == '+'))
                        {
                            if (err == 0)
                            {
                            floatOrNot = 0;
                            std::cout << templine[j] << "  => ";
                            std::cerr << "Error with value" << std::endl;
                            err = 1;
                            }
                            //std::getline(file, line);
            
                            
                        }
                    }
                    else
                    {
                        if (err == 0)
                        {
                        std::cout << templine[j] << "  => ";
                        std::cerr << "Error with value.." << std::endl;
                        err = 1;
                        }
                    //std::getline(file, line);
    
                   
                    }
                }
                j++;
            }
                if (!templine[j])
                {
                    long long int value = std::atol(svalue.c_str());
                    float fvalue = std::atof(svalue.c_str());
                    if (value > 2147483647 || value < -2147483648)
                    {
                        if (err == 0)
                        {
                        err = 1;
                        std::cout << value << "  => ";
                        std::cerr << "Error: To large a number" << std::endl;
                        }
                        //std::getline(file, line);
        
                    }
                    else if (value <= 0)
                    {
                        if (err == 0)
                        {
                        err = 1;
                        std::cout << value << "  => ";
                        std::cerr << "Error: not a positive number." << std::endl;
                        }
                        //std::getline(file, line);
        
                    }
                    else if (value >= 1000)
                    {
                        if (err == 0)
                        {
                        err = 1;
                        std::cout << value << "  => ";
                        std::cerr << "Error: value must be set BETWEEN 0 and 1000" << std::endl;
                        //std::getline(file, line);
                        }
        
                    
                    }
                    else
                    {
                    if (floatOrNot == 1)
                    {
                        std::cout << fvalue << std::endl;
                        floatOrNot = 0;
                    }
                    else
                        std::cout << value << std::endl;    
                    }
                }
        j = 0;
        }
        i++; 
    }
    return (0);
}