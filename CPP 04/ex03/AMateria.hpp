/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:39:29 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/19 11:04:34 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
    protected:
    std::string _type;
    
    public:
    AMateria(std::string const & type);

    //Orthodox Canonical Form
    AMateria(); //default constructor
    AMateria(const AMateria&	newAMateria); //cpy constructor
    AMateria& operator=(AMateria const & objectToCopy); //Copy assignment operator
    virtual ~AMateria() = 0; //destructor

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif