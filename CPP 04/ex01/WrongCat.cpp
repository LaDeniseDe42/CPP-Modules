/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:01:31 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/05 13:18:18 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//CONSTRUCTEURS

//default
WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "\033[33mWrongCat default constructor called \033[0m " << std::endl;
}

//constructor with string
WrongCat::WrongCat(std::string type)
{
    std::cout << "\033[33mWrongCat constructor with name called\033[0m " << std::endl;
	this->type = type;
}

//cpy constructor
WrongCat::WrongCat(const WrongCat&	newWrongCat)
{ 
	std::cout << "\033[33mWrongCat Copy constructor called\033[0m " << std::endl;
	*this = newWrongCat;
}

//Copy assignment operator
WrongCat& WrongCat::operator=(WrongCat const & objectToCopy)
{
	std::cout << "\033[33mWrongCat Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
		this->type = objectToCopy.type;
	}
	return (*this);
}

//destructor
WrongCat::~WrongCat()
{
	std::cout << "Hey you i'm \033[36mWrongCat\033[0m destructor" << std::endl;
}

//FUNCTIONS

void WrongCat::makeSound() const
{
    std::cout << "WrongMiaou WrongMiaou WrongMiaou" << std::endl;
}

std::string WrongCat::getType() const
{
    return (this->type);
}