/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:17:32 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/16 14:00:27 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//CONSTRUCTEURS

//default
Ice::Ice()
{
	this->type = "ice";
	std::cout << "\033[33mIce default constructor called \033[0m " << std::endl;
}

//constructor with string
Ice::Ice(std::string type)
{
    std::cout << "\033[33mIce constructor with name called\033[0m " << std::endl;
	this->type = type;
}

//cpy constructor
Ice::Ice(const Ice&	newIce)
{ 
	std::cout << "\033[33mIce Copy constructor called\033[0m " << std::endl;
	*this = newIce;
}

//Copy assignment operator
Ice& Ice::operator=(Ice const & objectToCopy)
{
	std::cout << "\033[33mIce Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
		this->type = objectToCopy.type;
	}
	return (*this);
}

//destructor
Ice::~Ice()
{
	std::cout << "Hey you i'm \033[36mIce\033[0m destructor" << std::endl;
}
