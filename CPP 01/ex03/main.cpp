/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:41:03 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/19 16:08:19 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include"HumanB.hpp"

int	main()
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	
	// Weapon club = Weapon("crude spiked club");
	// HumanB jim("Jim");
	// jim.setWeapon(club);
	// jim.attack();
	// club.setType("some other type of club");
	// jim.attack();
	return (0);
}