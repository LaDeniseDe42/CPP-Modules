/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:26:10 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/18 16:19:31 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//CONSTRUCTEURS

//default
Cure::Cure()
{
	this->_type = "cure";
	std::cout << "\033[33mCure default constructor called \033[0m " << std::endl;
}

//cpy constructor
Cure::Cure(const Cure&	newCure)
{ 
	std::cout << "\033[33mCure Copy constructor called\033[0m " << std::endl;
	*this = newCure;
}

//Copy assignment operator
Cure& Cure::operator=(Cure const & objectToCopy)
{
	std::cout << "\033[33mCure Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
		this->_type = objectToCopy._type;
	}
	return (*this);
}

//destructor
Cure::~Cure()
{
	std::cout << "Hey you i'm \033[36mCure\033[0m destructor" << std::endl;
}

//FUNCTIONS
AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals <";
	std::cout << target.getName();
	std::cout << "’s wounds *" << std::endl;
}