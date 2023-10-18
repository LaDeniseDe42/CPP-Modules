/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:18:13 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/04 15:06:33 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP


#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string Name;
    int HitPoints;
    int EnergyPoints;
    int AttackDamage;

public:
    //Orthodox Canonical Form
    ClapTrap(); //default constructor
    ClapTrap(const ClapTrap&	newClaptrap); //cpy constructor
    ClapTrap& operator=(ClapTrap const & objectToCopy); //Copy assignment operator
    ~ClapTrap(); //destructor

    ClapTrap(std::string Name);//constructor with string

    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);
    std::string  getName() const;
    int getIntValue(std::string what) const;
    void setName(std::string name);
};


#endif