/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:42:49 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/19 14:48:43 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <cstring>

class Weapon
{
	private:
		std::string	type_;

	public:
		Weapon();
		Weapon(std::string nameOfWeapon);
		~Weapon();
		const std::string&	getType();
		void				setType(std::string newType);
};

#endif