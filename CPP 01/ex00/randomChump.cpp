/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:21:47 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/18 15:01:55 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


//It creates a zombie, name it, and the zombie announces itself.
void	Zombie::randomChump(std::string name)
{
	Zombie zombie;

	zombie.name = name;
    zombie.announce();
}
