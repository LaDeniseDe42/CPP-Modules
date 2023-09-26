/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:44:18 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/19 15:08:42 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_HPP
# define HumanA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
	std::string	name_;
	Weapon		&weapon_;

	public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack();
	
};

#endif