/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:45:38 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/19 15:48:08 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP
# define HumanB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
	std::string	name_;
	Weapon		*weapon_;

	public:
	HumanB(std::string name);
	~HumanB();
	void	setWeapon(const Weapon &weapon);
	void	attack();

}; 

#endif