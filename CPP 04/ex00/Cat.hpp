/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:41:18 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/05 12:03:03 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    protected:
    
    std::string type;
    
    public:
    //Orthodox Canonical Form
    Cat(); //default constructor
    Cat(const Cat&	newCat); //cpy constructor
    Cat& operator=(Cat const & objectToCopy); //Copy assignment operator
    ~Cat(); //destructor

    Cat(std::string type);//constructor with string
    void makeSound() const;
    std::string getType() const;
};

#endif