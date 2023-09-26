/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:45:12 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/19 15:56:40 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name_ = name;
	this->weapon_ = NULL;
}

HumanB::~HumanB()
{
	
}

void	HumanB::setWeapon(const Weapon &weapon)
{
	this->weapon_ = (Weapon*)&weapon;
}

void	HumanB::attack()
{
	if (this->weapon_ != NULL)
	{
		std::cout << "\033[33m";
		std::cout << this->name_ << " \033[31mattacks with their\033[33m ";
		std::cout << weapon_->getType() << std::endl;
		std::cout << "\033[0m";
	}
	else
	{
		std::cout << "\033[31m";
		std::cout << this->name_ << " can't attack because they have no weapon.\033[0m" << std::endl;
	}
}