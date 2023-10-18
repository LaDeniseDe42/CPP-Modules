/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:18:18 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/04 14:55:05 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    ClapTrap    b("Arthas");
    b.attack("Uther");
    b.takeDamage(4);
    b.beRepaired(12);
    std::cout << b.getName() << " have " << b.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << b.getIntValue("HitPoints") << " HP." << std::endl;

    std::cout << std::endl;
    ScavTrap    a("Hodor");
    a.attack("NightWalker");
    a.takeDamage(42);
    a.beRepaired(12);
    a.guardGate();
    std::cout << a.getName() << " have " << a.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << a.getIntValue("HitPoints") << " HP." << std::endl;

    std::cout << std::endl;
    ScavTrap c;
    c = a;
    c.setName("Obi-wan");
    c.attack("Dark Maul");
    c.takeDamage(42);
    c.beRepaired(12);
    c.guardGate();
    std::cout << c.getName() << " have " << c.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << c.getIntValue("HitPoints") << " HP." << std::endl;


    std::cout << std::endl;
    return (0);
}