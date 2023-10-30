/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:18:18 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/30 09:04:33 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    ClapTrap    b("Arthas");
    std::cout << b.getName() << " have " << b.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << b.getIntValue("HitPoints") << " HP." << std::endl;
    b.attack("Uther");
    b.takeDamage(9);
    b.beRepaired(12);
    std::cout << b.getName() << " have " << b.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << b.getIntValue("HitPoints") << " HP." << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    ClapTrap    c;
    c = b;
    c.setName("Medhiv");
    std::cout << c.getName() << " have " << c.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << c.getIntValue("HitPoints") << " HP." << std::endl;
    c.attack("Archimonde");
    c.takeDamage(9);
    c.beRepaired(12);
    std::cout << c.getName() << " have " << c.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << c.getIntValue("HitPoints") << " HP." << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;
    ClapTrap    d(c);
    d.setName("Anubarak");
    std::cout << d.getName() << " have " << d.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << d.getIntValue("HitPoints") << " HP." << std::endl;
    d.attack("Illidan");
    d.attack("Illidan");
    d.attack("Illidan");
    d.attack("Illidan");
    d.attack("Illidan");
    d.attack("Illidan");
    d.takeDamage(9);
    d.beRepaired(12);
    std::cout << d.getName() << " have " << d.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << d.getIntValue("HitPoints") << " HP." << std::endl;
    std::cout << std::endl;
    
    return (0);
}