/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:47:49 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/10 09:58:28 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//On utilise le dynamic_cast pour effectuer des conversions entre des types polymorphiques



//It randomly instanciates A, B or C and returns the instance as a Base pointer.
//Feel free to use anything you like for the random choice implementation.
Base *generate(void)
{
    srand(time(NULL));
    int i = rand() % 3;     
    if (i == 0)
        return (new A());
    else if (i == 1)
        return (new B());
    else
        return (new C());
        
}
    
//It prints the actual type of the object pointed to by p: "A", "B" or "C".
//Si le if reussi, renvoie un pointeur vers la classe A, sinon NULL ect..
void identify(Base* BasePointYourClass)
{
    std::cout << "identify(Base* p)" << std::endl;
    if (dynamic_cast<A*>(BasePointYourClass))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(BasePointYourClass))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(BasePointYourClass))
        std::cout << "C" << std::endl;
    else
        std::cerr << "bad Base initialisation" << std::endl;
}
    
//It prints the actual type of the object pointed to by p: "A", "B" or "C".
//Using a pointer inside this function is forbidden.
//utiliser une reference avec dynamic cast renvoi forcement une exception en cas d'echec
void identify(Base& p)
{
    std::cout << "identify(Base& p)" << std::endl;
    try
    {
        A &a = dynamic_cast<A&>(p);//si la conversion est reussi, p est bien de type a. Sinon exception bad cast
        std::cout << "A" << std::endl;
        (void)a;
    }
    catch(const std::exception& e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            (void)b;
        }
        catch(const std::exception& e)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
                (void)c;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
    
}
    
int main()
{
    //stock l'adresse de A, B ou C dans base
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    std::cout << std::endl;

    Base *base1 = generate();
    identify(base1);
    identify(*base1);
    delete base1;
    std::cout << std::endl;

    //test avec un pointeur NULL
    Base *base2 = NULL;
    identify(base2);
    identify(*base2);
    std::cout << std::endl;
    
    //stock l'adresse d'une base
    Base *base3 = new Base();
    identify(base3);
    identify(*base3);
    delete base3;
    
    return (0);
}