/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:10:07 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/19 09:47:16 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "Patrick le papa Zombie du main";
	return;
}

Zombie::~Zombie()
{
	if (this->name == "Patrick le papa Zombie du main")
		std::cout << "\033[30m" << "<< Thx for this good meal bro, see you! >> say Patrick" << std::endl;
	else if (this->name == "")
		std::cout << "there is nobody to kill with the destructor" << std::endl;
	else
		std::cout << "\033[33mI'm the destructor and i will deleted : \033[35m" << this->name << std::endl;
	std::cout << "\033[0m";
	return;
}

void	Zombie::announce()
{
	std::cout << "\033[36m";
	std::cout << this->name; 
	std::cout << " : BraiiiiiiinnnzzzZ...\033[0m" << std::endl;
}
