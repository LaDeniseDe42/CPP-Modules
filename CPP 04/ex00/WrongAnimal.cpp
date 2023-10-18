/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:46:27 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/05 13:19:48 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//CONSTRUCTEURS

//default
WrongAnimal::WrongAnimal()
{
	this->type = "WrongUnknown";
	std::cout << "\033[33mWrongAnimal default constructor called \033[0m " << std::endl;
}

//constructor with string
WrongAnimal::WrongAnimal(std::string type)
{
    std::cout << "\033[33mWrongAnimal constructor with name called\033[0m " << std::endl;
	this->type = type;
}

//cpy constructor
WrongAnimal::WrongAnimal(const WrongAnimal&	newWrongAnimal)
{ 
	std::cout << "\033[33mWrongAnimal Copy constructor called\033[0m " << std::endl;
	*this = newWrongAnimal;
}

//Copy assignment operator
WrongAnimal& WrongAnimal::operator=(WrongAnimal const & objectToCopy)
{
	std::cout << "\033[33mWrongAnimal Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
		this->type = objectToCopy.type;
	}
	return (*this);
}

//destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "Hey you i'm \033[36mWrongAnimal\033[0m destructor" << std::endl;
}


//FUNCTIONS

void WrongAnimal::makeSound() const
{
    std::cout << "You heard a \033[36mWrongUndefined\033[0m sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}