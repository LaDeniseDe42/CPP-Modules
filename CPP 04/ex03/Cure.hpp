/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:25:14 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/18 11:47:15 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
     //Orthodox Canonical Form
    Cure(); //default constructor
    Cure(const Cure&	newCure); //cpy constructor
    Cure& operator=(Cure const & objectToCopy); //Copy assignment operator
    ~Cure(); //destructor

     // CURE FUNCTIONS
    virtual AMateria *clone() const;
    virtual void use(ICharacter& target);
};

#endif