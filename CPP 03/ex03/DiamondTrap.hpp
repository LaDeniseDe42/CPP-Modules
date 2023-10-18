/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:22:02 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/04 14:25:38 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string Name;

    public:
        //Orthodox Canonical Form
        DiamondTrap(); //default constructor
        DiamondTrap(const DiamondTrap&	newDiamondTrap); //cpy constructor
        DiamondTrap& operator=(DiamondTrap const & objectToCopy); //Copy assignment operator
        ~DiamondTrap(); //destructor

        DiamondTrap(std::string Name);
        void whoAmI();
        void attack(const std::string& target);
        std::string  getName() const;

};





#endif