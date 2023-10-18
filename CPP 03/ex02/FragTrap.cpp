/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:29:01 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/04 15:07:42 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


//CONSTRUCTEURS

//default
FragTrap::FragTrap()
{
	std::cout << "\033[32mFragTrap default constructor called\033[0m" << std::endl;
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}

//constructor with string
FragTrap::FragTrap(std::string Name)
{
    std::cout << "\033[32mFragTrap constructor with name called\033[0m " << std::endl;
	this->Name = Name;
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}

//cpy constructor
FragTrap::FragTrap(const FragTrap&	newFragTrap)
{ 
	std::cout << "\033[32mFragTrap Copy constructor called\033[0m " << std::endl;
	*this = newFragTrap;
}

//Copy assignment operator
FragTrap& FragTrap::operator=(FragTrap const & objectToCopy)
{
	std::cout << "\033[32mFragTrap Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
		this->Name = objectToCopy.Name;
        this->HitPoints = objectToCopy.HitPoints;
        this->EnergyPoints = objectToCopy.EnergyPoints;
        this->AttackDamage = objectToCopy.AttackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "\033[32mI'm the FragTrap destructor and i'm coming for you " << getName() << "\033[0m" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "COME ON GUUUUYS, GIVE ME A HIGHFIVES !" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
		if (this->HitPoints == 0)
		std::cout << "you are dead and you cant \033[31mrepair\033[0m anything" << std::endl;
	else if (this->EnergyPoints == 0)
		std::cout << "you are to tired for using repair capacity" << std::endl;
	else
	{
		std::cout << getName() << " use is capacity for \033[31mrepair\033[0m himself \033[34;4m" << amount << "\033[0m HP" << std::endl;
		this->EnergyPoints--;
		this->HitPoints = this->HitPoints + amount;
		if (this->HitPoints > 100)
		{
			this->HitPoints = 100;
		}
	}
}