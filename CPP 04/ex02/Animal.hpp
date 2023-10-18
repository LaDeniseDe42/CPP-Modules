/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:40:27 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/16 11:27:45 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>
#include <string>

class Animal
{
    protected:
    
    std::string type;
    
    public:
    //Orthodox Canonical Form
    Animal(); //default constructor
    Animal(const Animal&	newAnimal); //cpy constructor
    Animal& operator=(Animal const & objectToCopy); //Copy assignment operator
    virtual ~Animal() = 0; //destructor

    Animal(std::string type);//constructor with string
    virtual void  makeSound() const;
    virtual std::string  getType() const;
    virtual void setDogIdeas();
    virtual void getDogIdeas();
    virtual void setCatIdeas();
    virtual void getCatIdeas();
};

#endif