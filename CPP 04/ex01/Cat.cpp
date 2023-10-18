/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:41:30 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/06 15:25:39 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//CONSTRUCTEURS

//default
Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain;
	setCatIdeas();
	std::cout << "\033[33mCat default constructor called \033[0m " << std::endl;
}

//constructor with string
Cat::Cat(std::string type)
{
	setCatIdeas();
    std::cout << "\033[33mCat constructor with name called\033[0m " << std::endl;
	this->brain = new Brain; 
	this->type = type;
}

//cpy constructor
Cat::Cat(const Cat&	newCat)
{ 
	std::cout << "\033[33mCat Copy constructor called\033[0m " << std::endl;
	this->brain = new Brain(*newCat.brain);
	*this = newCat;
}

//Copy assignment operator
Cat& Cat::operator=(Cat const & objectToCopy)
{
	std::cout << "\033[33mCat Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
		this->brain = new Brain(*objectToCopy.brain);
	}
	return (*this);
}

//destructor
Cat::~Cat()
{
	delete brain;
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

void Cat::setCatIdeas()
{
	//this->ideas->setIdeas("I Would like a bone");
	this->brain->setIdeas("I Would like take world control", "Human, I will kill you for your meat");
}

void Cat::getCatIdeas()
{
	//return (this->ideas->getIdeas());
	//return (this->brain->getIdeas());
	this->brain->getIdeas();
}