/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:23:08 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/15 13:02:12 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <stdlib.h>
#include <limits>
#include <iomanip>
#include <stdint.h>

class Data
{
    private:
        int dataInt;
        std::string dataStr;
        
    public:
    //Orthodox Canonical Data
    Data();//default constructor
    ~Data();//destructor
    Data(const Data&	newData); //cpy constructor
    Data(int dataInt, std::string dataStr);
    Data(std::string dataStr);
    Data(int dataInt);
    Data& operator=(Data const & objectToCopy); //Copy assignment operator
    
    int getIntValue();
    std::string getStrValue();
        
};