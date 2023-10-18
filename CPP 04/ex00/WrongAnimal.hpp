/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:00:26 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/05 12:25:46 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP


#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
    
    std::string type;
    
    public:
    //Orthodox Canonical Form
    WrongAnimal(); //default constructor
    WrongAnimal(const WrongAnimal&	newWrongAnimal); //cpy constructor
    WrongAnimal& operator=(WrongAnimal const & objectToCopy); //Copy assignment operator
    ~WrongAnimal(); //destructor

    WrongAnimal(std::string type);//constructor with string
    void  makeSound() const;
    std::string  getType() const;
};

#endif