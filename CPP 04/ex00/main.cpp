/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:39:53 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/30 10:29:09 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"



int main()
{
    const Animal* meta = new Animal();
    std::cout << std::endl;
    const Animal* j = new Dog();
    std::cout << std::endl;
    const Animal* i = new Cat();
    std::cout << std::endl;
    const WrongAnimal* wrong = new WrongAnimal();
    std::cout << std::endl;
    const WrongAnimal*    wrong2 = new WrongCat();
    std::cout << std::endl;
    
    std::cout << "\033[35m" << i->getType() << " \033[0m" << std::endl;
    i->makeSound();//cat
    std::cout << std::endl;
    std::cout << "\033[35m" << j->getType() << " \033[0m" << std::endl;
    j->makeSound();//dog
    std::cout << std::endl;
    std::cout << "\033[35m" << meta->getType() << " \033[0m" << std::endl;
    meta->makeSound();//Animal
    std::cout << std::endl;

    std::cout << "\033[35m" << wrong->getType() << " \033[0m" << std::endl;
    wrong->makeSound();//WrongAnimal
    std::cout << std::endl;
    std::cout << "\033[35m" << wrong2->getType() << " \033[0m" << std::endl;
    wrong2->makeSound();//wrongCat

    std::cout << std::endl;
    delete  wrong;
     std::cout << std::endl;
    delete  wrong2;
     std::cout << std::endl;
    delete  meta;
     std::cout << std::endl;
    delete  j;
     std::cout << std::endl;
    delete  i;
     std::cout << std::endl;
    return (0);
}