/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:18:18 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/03 15:17:58 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


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
    FragTrap    a("Gollum");
    std::cout << "Give me back MY PRECIOUUUUUUS !" << std::endl;
    a.attack("Frodon");
    a.takeDamage(42);
    a.beRepaired(12);
    a.highFivesGuys();
    std::cout << a.getName() << " have " << a.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << a.getIntValue("HitPoints") << " HP." << std::endl;

    std::cout << std::endl;
    FragTrap c;
    c = a;
    c.setName("Dobby");
    c.attack("Croutard");
    c.takeDamage(42);
    c.beRepaired(12);
    a.highFivesGuys();
    std::cout << c.getName() << " have " << c.getIntValue("EnergyPoints") << " energy";
    std::cout << " and "  << c.getIntValue("HitPoints") << " HP." << std::endl;


    std::cout << std::endl;
    return (0);
}