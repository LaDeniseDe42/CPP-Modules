/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:39:53 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/16 09:58:26 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"



int main()
{

    const Animal* q = new Dog();
    const Animal* u = new Cat();
    delete q;//should not create a leak
    delete u;
    std::cout << std::endl;


    Animal* animals[6];

    for (int i = 0; i < 3; i++)
    {
        animals[i] = new Dog();
        std::cout << animals[i]->getType() << " : ";
        animals[i]->makeSound();
        //animals[i]->getDogIdeas();
        std::cout << std::endl;
    }

    for (int i = 3; i < 6; i++)
    {
        animals[i] = new Cat();
        std::cout << animals[i]->getType() << " : ";
        animals[i]->makeSound();
        //animals[i]->getCatIdeas();
        std::cout << std::endl;
    }

    for (int i = 0; i < 6; i++)
    {
        delete animals[i];
        std::cout << std::endl;
    }
    return (0);
}