/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:25:14 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/18 16:12:22 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
//#include "ICharacter.hpp"


class Cure : public AMateria
{
    public :
    
     //Orthodox Canonical Form
    Cure(); //default constructor
    Cure(const Cure&	newCure); //cpy constructor
    Cure& operator=(Cure const & objectToCopy); //Copy assignment operator
    ~Cure(); //destructor

     // CURE FUNCTIONS
    AMateria *clone() const;
    void use(ICharacter& target);
};

#endif