/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:43:12 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/19 14:49:29 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){
}

Weapon::Weapon(std::string nameOfWeapon)
{
	this->type_ = nameOfWeapon;
}

Weapon::~Weapon(){	
}

const std::string& Weapon::getType()
{
	return (this->type_);
}

void	Weapon::setType(std::string newType)
{
	this->type_ = newType;
}
