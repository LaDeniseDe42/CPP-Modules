/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:38:35 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/19 15:12:29 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{

IMateriaSource* src = new MateriaSource();
std::cout << "          ------          " << std::endl;
src->learnMateria(new Ice());
std::cout << "          ------          " << std::endl;
src->learnMateria(new Cure());
src->learnMateria(new Cure());
src->learnMateria(new Cure());
src->learnMateria(new Cure());
std::cout << "          ------          " << std::endl;

ICharacter* me = new Character("Quentin");
AMateria* tmp;
std::cout << "          ------          " << std::endl;
tmp = src->createMateria("ice");
std::cout << "          ------          " << std::endl;
me->equip(tmp);
std::cout << "          ------          " << std::endl;
tmp = src->createMateria("cure");
me->equip(tmp);

ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
me->use(8, *bob);
std::cout << "          ------          " << std::endl;
me->unequip(1);
me->unequip(2);

delete bob;
delete me;
delete src;
delete tmp; // delete l'equipement numero 1 seulement si UNEQUIP
return 0;
}