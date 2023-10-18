/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:41:05 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/06 15:23:27 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:

    Brain* brain;
    
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

    void setDogIdeas();
    void getDogIdeas();
};

#endif