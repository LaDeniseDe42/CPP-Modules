/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:30:15 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/18 14:37:04 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"


class Character : public ICharacter
{
    private :
    AMateria* slots[4];
    std::string name;


    public:

    //Orthodox Canonical Form
    Character(); //default constructor
    Character(const Character&	newCharacter); //cpy constructor
    Character& operator=(Character const & objectToCopy); //Copy assignment operator
    ~Character(); //destructor
    Character(std::string const &name); // constructor with name

    std::string const & getName() const
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};


#endif