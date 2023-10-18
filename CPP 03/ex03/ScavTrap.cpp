/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:14:11 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/04 12:33:40 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//CONSTRUCTEURS

//default
ScavTrap::ScavTrap()
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "\033[32mSCAVTRAP default constructor called\033[0m" << std::endl;
}

//constructor with string
ScavTrap::ScavTrap(std::string Name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
    std::cout << "\033[32mSCAVTRAP constructor with name called\033[0m " << std::endl;
	this->Name = Name;
}

//cpy constructor
ScavTrap::ScavTrap(const ScavTrap&	newScavTrap)
{ 
	std::cout << "\033[32mSCAVTRAP Copy constructor called\033[0m " << std::endl;
	*this = newScavTrap;
}

//Copy assignment operator
ScavTrap& ScavTrap::operator=(ScavTrap const & objectToCopy)
{
	std::cout << "\033[32mSCAVTRAP Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
		this->Name = objectToCopy.Name;
        this->HitPoints = objectToCopy.HitPoints;
        this->EnergyPoints = objectToCopy.EnergyPoints;
        this->AttackDamage = objectToCopy.AttackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "\033[32mI'm the SCAVTRAP destructor and i'm coming for you " << getName() << "\033[0m" << std::endl;
}


void ScavTrap::guardGate()
{
	std::cout << getName() << " active Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (getIntValue("EnergyPoints") == 0)
	{
		std::cout << getName() << " is to tired for a fight" << std::endl;
	}
	else if (getIntValue("HitPoints") == 0)
	{
		std::cout << getName() << " is DEAD and Dead cant attack" << std::endl;
	}
	else
	{
		std::cout << getName() << " \033[31m attack \033[0m " << target << " and causing \033[34;4m" << getIntValue("AttackDamage");
		std::cout << "\033[0m violent points of damage!" << std::endl;	
	}
	this->EnergyPoints--;
}