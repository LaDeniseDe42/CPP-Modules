/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:49:17 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/30 10:16:31 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


//CONSTRUCTEURS

//default
DiamondTrap::DiamondTrap()
{
	std::cout << "\033[32mDiamondTrap default constructor called\033[0m" << std::endl;
    this->Name = "Default";
    ClapTrap::Name = Name + "_clap_name";
    this->AttackDamage = 30;
    this->HitPoints = 100;
    this->EnergyPoints = 50;
}

//constructor with string
DiamondTrap::DiamondTrap(std::string Name)
{
    std::cout << "\033[32mDiamondTrap constructor with name called\033[0m " << std::endl;
	ClapTrap::Name = Name + "_clap_name";
    this->Name = Name;
    this->AttackDamage = 30;
    this->HitPoints = 100;
    this->EnergyPoints = 50;

}

//cpy constructor
DiamondTrap::DiamondTrap(const DiamondTrap&	newDiamondTrap)
{ 
	std::cout << "\033[32mDiamondTrap Copy constructor called\033[0m " << std::endl;
	*this = newDiamondTrap;
}

//Copy assignment operator
DiamondTrap& DiamondTrap::operator=(DiamondTrap const & objectToCopy)
{
	std::cout << "\033[32mDiamondTrap Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
		ClapTrap::Name = objectToCopy.Name + "_clap_trap";
        this->Name = objectToCopy.Name;
        this->FragTrap::HitPoints = objectToCopy.HitPoints;
        this->ScavTrap::EnergyPoints = objectToCopy.EnergyPoints;
        this->FragTrap::AttackDamage = objectToCopy.AttackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "\033[32mI'm the DiamondTrap destructor and i'm coming for you " << this->Name << "\033[0m" << std::endl;
}


void    DiamondTrap::whoAmI(void)
{
    std::cout << "I am DiamondTrap " << this->Name << " and my ancestor ClapTrap name is " << ClapTrap::getName() << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{

    ScavTrap::attack(target);
}

std::string  DiamondTrap::getName() const
{
    return (this->Name);
}