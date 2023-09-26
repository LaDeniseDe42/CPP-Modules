/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:06:08 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/19 09:35:51 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::zombieHorde(int N, std::string name)
{
	size_t	i = 0;

	Zombie *horde = new Zombie[N];
	while (i < (size_t)N)
	{
		horde[i].name = name;
		i++;
	}
	return (horde);
}