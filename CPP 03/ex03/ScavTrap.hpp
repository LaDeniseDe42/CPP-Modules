/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:48:15 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/04 11:25:20 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP


#include "ClapTrap.hpp"


class ScavTrap : virtual public ClapTrap
{
    public:
    //Orthodox Canonical Form
    ScavTrap(); //default constructor
    ScavTrap(const ScavTrap&	newScavTrap); //cpy constructor
    ScavTrap& operator=(ScavTrap const & objectToCopy); //Copy assignment operator
    ~ScavTrap(); //destructor

    ScavTrap(std::string Name);
    
    void guardGate();
    void attack(const std::string& target);
};








#endif