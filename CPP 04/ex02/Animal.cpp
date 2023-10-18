/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:46:27 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/16 11:19:06 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//CONSTRUCTEURS

//default
Animal::Animal()
{
	this->type = "Unknown";
	std::cout << "\033[33mAnimal default constructor called \033[0m " << std::endl;
}

//constructor with string
Animal::Animal(std::string type)
{
    std::cout << "\033[33mAnimal constructor with name called\033[0m " << std::endl;
	this->type = type;
}

//cpy constructor
Animal::Animal(const Animal&	newAnimal)
{ 
	std::cout << "\033[33mAnimal Copy constructor called\033[0m " << std::endl;
	*this = newAnimal;
}

//Copy assignment operator
Animal& Animal::operator=(Animal const & objectToCopy)
{
	std::cout << "\033[33mAnimal Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
		this->type = objectToCopy.type;
	}
	return (*this);
}

//destructor
Animal::~Animal()
{
	std::cout << "Hey you i'm \033[36mAnimal\033[0m destructor" << std::endl;
}


//FUNCTIONS

void Animal::makeSound() const
{
    std::cout << "You heard an undefined sound" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::setDogIdeas()
{

}

void Animal::getDogIdeas()
{
	
}

void Animal::setCatIdeas()
{

}

void Animal::getCatIdeas()
{
	
}