/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:02:30 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/05 12:25:35 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    protected:
    
    std::string type;
    
    public:
    //Orthodox Canonical Form
    WrongCat(); //default constructor
    WrongCat(const WrongCat&	newWrongCat); //cpy constructor
    WrongCat& operator=(WrongCat const & objectToCopy); //Copy assignment operator
    ~WrongCat(); //destructor

    WrongCat(std::string type);//constructor with string
    void makeSound() const;
    std::string getType() const;
};

#endif