/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:05:33 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/19 09:22:53 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <cstring>
#include <iostream>

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