/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:05:33 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/29 14:45:00 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <cstring>
#include <iostream>
#include <cstdlib>

class Zombie
{
	private:

	std::string name;

	public:

	Zombie();
	~Zombie( void );
	void	announce(void);
	Zombie	*zombieHorde(int N, std::string name);
};

#endif