/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:17:32 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/18 16:19:22 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//CONSTRUCTEURS

//default
Ice::Ice()
{
	this->_type = "ice";
	std::cout << "\033[33mIce default constructor called \033[0m " << std::endl;
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
		this->_type = objectToCopy._type;
	}
	return (*this);
}

//destructor
Ice::~Ice()
{
	std::cout << "Hey you i'm \033[36mIce\033[0m destructor" << std::endl;
}

//FUNCTIONS
AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at ";
	std::cout << target.getName();
	std::cout << " *" << std::endl;
}
