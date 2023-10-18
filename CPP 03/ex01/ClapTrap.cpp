/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:18:10 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/04 14:56:57 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//CONSTRUCTEURS

//default
ClapTrap::ClapTrap() : HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "\033[33mdefault constructor called \033[0m " << std::endl;
}

//constructor with string
ClapTrap::ClapTrap(std::string Name) : HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "\033[33mconstructor with name called\033[0m " << std::endl;
	this->Name = Name;
}

//cpy constructor
ClapTrap::ClapTrap(const ClapTrap&	newClaptrap)
{ 
	std::cout << "\033[33mCopy constructor called\033[0m " << std::endl;
	*this = newClaptrap;
}

//Copy assignment operator
ClapTrap& ClapTrap::operator=(ClapTrap const & objectToCopy)
{
	std::cout << "\033[33mCopy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
		this->Name = objectToCopy.Name;
        this->HitPoints = objectToCopy.HitPoints;
        this->EnergyPoints = objectToCopy.EnergyPoints;
        this->AttackDamage = objectToCopy.AttackDamage;
	}
	return (*this);
}


//Functions members

 std::string  ClapTrap::getName() const
 {
	return (this->Name);
 }

int ClapTrap::getIntValue(std::string what) const
{
	if (what == "HitPoints")
		return (this->HitPoints);
	else if (what == "EnergyPoints")
		return (this->EnergyPoints);
	else if (what == "AttackDamage")
		return (this->AttackDamage);
	return (1);
}

void ClapTrap::attack(const std::string& target)
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
		std::cout << getName() << " \033[31mattack\033[0m " << target << " and causing \033[34;4m" << getIntValue("AttackDamage");
		std::cout << "\033[0m points of damage!" << std::endl;	
	}
	this->EnergyPoints--;

}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << getName() << " \033[31mtake\033[0m \033[34;4m" << amount << "\033[0m\033[31m damage\033[0m" << std::endl;
	this->HitPoints = this->HitPoints - amount;
	if (this->HitPoints < 0)
		this->HitPoints = 0; 
	std::cout << getName() << " have \033[34;4m" << getIntValue("HitPoints") << "\033[0m HP left after this attack" << std::endl;
	if (getIntValue("HitPoints") == 0)
	{
		std::cout << getName() << " find death in battle after a last death rattle" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
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
		if (this->HitPoints > 10)
		{
			this->HitPoints = 10;
		}
	}
}

void ClapTrap::setName(std::string name)
{
	this->Name = name;
}



//DESTRUCTOR
ClapTrap::~ClapTrap()
{
	std::cout << "\033[33mI'm the destructor and i will destoy " << this->getName() << "\033[0m" << std::endl;
}