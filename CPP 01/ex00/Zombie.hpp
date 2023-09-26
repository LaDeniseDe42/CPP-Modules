/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:20:35 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/18 12:58:35 by qdenizar         ###   ########.fr       */
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
	Zombie* newZombie(std::string name);
	void	randomChump(std::string name);

};

#endif