/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:41:01 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/05 13:18:32 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//CONSTRUCTEURS

//default
Dog::Dog()
{
	this->type = "Dog";
	std::cout << "\033[33mDog default constructor called \033[0m " << std::endl;
}

//constructor with string
Dog::Dog(std::string type)
{
    std::cout << "\033[33mDog constructor with name called\033[0m " << std::endl;
	this->type = type;
}

//cpy constructor
Dog::Dog(const Dog&	newDog)
{ 
	std::cout << "\033[33mDog Copy constructor called\033[0m " << std::endl;
	*this = newDog;
}

//Copy assignment operator
Dog& Dog::operator=(Dog const & objectToCopy)
{
	std::cout << "\033[33mDog Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
		this->type = objectToCopy.type;
	}
	return (*this);
}

//destructor
Dog::~Dog()
{
	std::cout << "Hey you i'm \033[36mDog\033[0m destructor" << std::endl;
}

//FUNCTIONS

void Dog::makeSound() const
{
    std::cout << "Waf Waf Waf" << std::endl;
}

std::string Dog::getType() const
{
    return (this->type);
}