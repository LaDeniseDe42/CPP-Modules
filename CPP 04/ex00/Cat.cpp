/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:41:30 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/05 13:19:16 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//CONSTRUCTEURS

//default
Cat::Cat()
{
	this->type = "Cat";
	std::cout << "\033[33mCat default constructor called \033[0m " << std::endl;
}

//constructor with string
Cat::Cat(std::string type)
{
    std::cout << "\033[33mCat constructor with name called\033[0m " << std::endl;
	this->type = type;
}

//cpy constructor
Cat::Cat(const Cat&	newCat)
{ 
	std::cout << "\033[33mCat Copy constructor called\033[0m " << std::endl;
	*this = newCat;
}

//Copy assignment operator
Cat& Cat::operator=(Cat const & objectToCopy)
{
	std::cout << "\033[33mCat Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
		this->type = objectToCopy.type;
	}
	return (*this);
}

//destructor
Cat::~Cat()
{
	std::cout << "Hey you i'm \033[36mCat\033[0m destructor" << std::endl;
}

//FUNCTIONS

void Cat::makeSound() const
{
    std::cout << "Miaou Miaou Miaou" << std::endl;
}

std::string Cat::getType() const
{
    return (this->type);
}