/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:18:18 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/03 12:14:37 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    ClapTrap    b("Arthas");
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
    c.attack("Archimonde");
    c.takeDamage(9);
    c.beRepaired(12);
    std::cout << c.getName() << " have " << b.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << b.getIntValue("HitPoints") << " HP." << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;
    ClapTrap    d(c);
    d.setName("Anubarak");
    d.attack("Illidan");
    d.takeDamage(9);
    d.beRepaired(12);
    std::cout << d.getName() << " have " << b.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << b.getIntValue("HitPoints") << " HP." << std::endl;
    std::cout << std::endl;
    
    return (0);
}