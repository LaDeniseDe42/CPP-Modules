/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:22:37 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/06 15:49:20 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//CONSTRUCTEURS

//default
Brain::Brain()
{
	std::cout << "\033[33mBrain default constructor called \033[0m " << std::endl;
	setIdeas("default ideas", "Brain segfault");
}

//cpy constructor
Brain::Brain(const Brain&	newBrain)
{ 
	std::cout << "\033[33mBrain Copy constructor called\033[0m " << std::endl;
	*this = newBrain;
}

//Copy assignment operator
Brain& Brain::operator=(Brain const & objectToCopy)
{
	std::cout << "\033[33mBrain Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = objectToCopy.ideas[i];
		}
	}
	return (*this);
}

//destructor
Brain::~Brain()
{
	std::cout << "Hey you i'm \033[36mBrain\033[0m destructor" << std::endl;
}

//FUNCTIONS

void Brain::setIdeas(std::string ideas, std::string ideas2)
{
	int	i = 0;

	while (i != 100)
	{
		if (i % 2 == 0)
		{
			this->ideas[i] = ideas;
		}
		else
			this->ideas[i] = ideas2;
		i++;
	}
}

void Brain::getIdeas()
{
	int	i = 0;
	while (i != 100)
	{
		std::cout << ideas[i] << std::endl;
		i++;
	}
}