/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:41:05 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/05 11:11:15 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    protected:
    
    std::string type;
    
    public:
    //Orthodox Canonical Form
    Dog(); //default constructor
    Dog(const Dog&	newDog); //cpy constructor
    Dog& operator=(Dog const & objectToCopy); //Copy assignment operator
    ~Dog(); //destructor

    Dog(std::string type);//constructor with string
    void makeSound() const;
    std::string getType() const;
};

#endif