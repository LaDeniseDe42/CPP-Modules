/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:39:27 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/18 16:18:44 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//CONSTRUCTEURS

//default
AMateria::AMateria()
{
	this->_type = "Unknown";
	std::cout << "\033[33mAMateria default constructor called \033[0m " << std::endl;
}

//constructor with string
AMateria::AMateria(std::string const & type)
{
    std::cout << "\033[33mAMateria constructor with name called\033[0m " << std::endl;
	this->_type = type;
}

//cpy constructor
AMateria::AMateria(const AMateria&	newAMateria)
{ 
	std::cout << "\033[33mAMateria Copy constructor called\033[0m " << std::endl;
	*this = newAMateria;
}

//Copy assignment operator
AMateria& AMateria::operator=(AMateria const & objectToCopy)
{
	std::cout << "\033[33mAMateria Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
		this->_type = objectToCopy._type;
	}
	return (*this);
}

//destructor
AMateria::~AMateria()
{
	std::cout << "Hey you i'm \033[36mAMateria\033[0m destructor" << std::endl;
}


//functions

std::string const & AMateria::getType() const //Returns the materia type
{
	return (this->_type);
}


void AMateria::use(ICharacter& target)
{
    (void)target;
}