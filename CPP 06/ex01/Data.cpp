/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:25:32 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/08 12:35:41 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

//CONSTRUCTEURS

//default
Data::Data()
{
	//std::cout << "\033[33mData default constructor called \033[0m " << std::endl;
    this->dataInt = 0;
    this->dataStr = "EMPTY";
}

//cpy constructor
Data::Data(const Data&	newData)
{ 
	//std::cout << "\033[33mData Copy constructor called\033[0m " << std::endl;
	*this = newData;
}


//Copy assignment operator
Data& Data::operator=(Data const & objectToCopy)
{
	//std::cout << "\033[33mData Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
        this->dataInt = objectToCopy.dataInt;
        this->dataStr = objectToCopy.dataStr;
	}
	return (*this);
}

Data::Data(int dataInt, std::string dataStr)
{
    this->dataInt = dataInt;
    this->dataStr = dataStr;

}

Data::Data(std::string dataStr)
{
    this->dataStr = dataStr;
}

Data::Data(int dataInt)
{
    this->dataInt = dataInt;
}

int Data::getIntValue()
{
    return (this->dataInt);
}

std::string Data::getStrValue()
{
    return (this->dataStr);
}


//DESTRUCTEUR

Data::~Data()
{
    //std::cout << "\033[33mData destructor called\033[0m " << std::endl;
}