/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:17:15 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/18 16:13:11 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
//#include "ICharacter.hpp"

class Ice : public AMateria
{
    public :

     //Orthodox Canonical Form
    Ice(); //default constructor

    Ice(const Ice&	newIce); //cpy constructor

    Ice& operator=(Ice const & objectToCopy); //Copy assignment operator

    ~Ice(); //destructor

    // ICE FUNCTIONS
    AMateria *clone() const;
    void use(ICharacter& target);

};

#endif