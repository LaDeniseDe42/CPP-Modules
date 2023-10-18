/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:18:18 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/04 15:15:56 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    ClapTrap    b("Brutus");
    b.attack("Cesar");
    b.takeDamage(101);
    b.beRepaired(12);
    std::cout << b.getName() << " have " << b.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << b.getIntValue("HitPoints") << " HP." << std::endl;

    std::cout << std::endl;
    FragTrap    y("Voldemort");
    y.attack("Harry");
    y.takeDamage(42);
    y.beRepaired(12);
    std::cout << y.getName() << " have " << y.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << y.getIntValue("HitPoints") << " HP." << std::endl;

    std::cout << std::endl;
    ScavTrap    z("Duncan");
    z.attack("Barron Harkonnen");
    z.takeDamage(42);
    z.beRepaired(12);
    std::cout << z.getName() << " have " << z.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << z.getIntValue("HitPoints") << " HP." << std::endl;

    DiamondTrap    a("Gollum");
    std::cout << std::endl;
    a.whoAmI();
    std::cout << "Give me back MY PRECIOUUUUUUS !" << std::endl;
    a.attack("Frodon");
    a.takeDamage(81);
    a.beRepaired(12);
    std::cout << a.getName() << " have " << a.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << a.getIntValue("HitPoints") << " HP." << std::endl;
 

    std::cout << std::endl;
    return (0);
}