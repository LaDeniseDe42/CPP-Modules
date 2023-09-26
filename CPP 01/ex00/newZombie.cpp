/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:21:27 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/18 15:01:48 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


//It creates a zombie, name it, and return it so you can use it outside of the function scope
Zombie*	Zombie::newZombie(std::string name)
{
	Zombie *newZombie = new Zombie;
	newZombie->name = name;
	return (newZombie);
}