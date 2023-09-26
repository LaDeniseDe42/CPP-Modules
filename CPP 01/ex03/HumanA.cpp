/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:44:56 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/19 15:52:55 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon_(weapon)
{

	this->name_ = name;
}

HumanA::~HumanA()
{
	
}

void	HumanA::attack()
{
	std::cout << "\033[33m";
	std::cout << this->name_ << " \033[31mattacks with their \033[33m";
	std::cout << this->weapon_.getType() << std::endl;
	std::cout << "\033[0m";
}