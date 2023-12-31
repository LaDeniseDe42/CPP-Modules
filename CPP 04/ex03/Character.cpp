/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:30:30 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/19 16:52:29 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//CONSTRUCTEURS

//default
Character::Character()
{
    for ( int i = 0; i < 4; i++)
    {
	    this->slots[i] = NULL;
    }
    this->name = "Unknow";
	std::cout << "\033[33mCharacter default constructor called \033[0m " << std::endl;
}


//cpy constructor
Character::Character(const Character&	newCharacter)
{ 
    
	std::cout << "\033[33mCharacter Copy constructor called\033[0m " << std::endl;
    this->name = newCharacter.name;
	for ( int i = 0; i < 4; i++)
    {
	    this->slots[i] = newCharacter.slots[i] ? newCharacter.slots[i]->clone() : NULL;
    }
}

//Copy assignment operator
Character& Character::operator=(Character const & objectToCopy)
{
	std::cout << "\033[33mCharacter Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
        this->name = objectToCopy.name;
		for ( int i = 0; i < 4; i++)
        {
            delete this->slots[i];
	        this->slots[i] = objectToCopy.slots[i] ? objectToCopy.slots[i]->clone() : NULL;
        }
	}
	return (*this);
}

//constructor with name
Character::Character(std::string const &name)
{
    this->name = name;
    for (int i = 0; i < 4; i++)
    {
        slots[i] = NULL;
    }
    if (name == "bob")
    {
        std::cout << "welcome in hell \033[31m" << name << "\033[0m" << ", i will shoot you but dont worry, i can heal you too" <<std::endl;
    }
    else
        std::cout << "welcome in your new world : \033[31m" << name << "\033[0m" << std::endl;
}

//destructor
Character::~Character()
{
	std::cout << "Hey you i'm \033[36mCharacter\033[0m destructor" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        delete this->slots[i];
    }
}


//FUNCTIONS

std::string const & Character::getName() const
{
    return (this->name);
}


void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->slots[i])
        {
            slots[i] = m;
            std::cout << "\033[31m" << this->name  << "\033[0m" << " equip " << m->getType() << " magic power !" << std::endl;
            break;
        }
        if (i == 3 && this->slots[3])
        {
            std::cout << "your inventory is full" << std::endl; 
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "this is not a valid slot" << std::endl;
    }
    else if (!this->slots[idx])
    {
        std::cout << "this slot is empty" << std::endl;
    }
    else
    {
        std::cout << "\033[31m" << this->name << "\033[0m" << " throw equiment on the floor .." << std::endl;
        this->slots[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->slots[idx])
    {
        std::cout << "\033[31m" << this->name  << "\033[0m" << " cast a spell and ";
        this->slots[idx]->use(target);
    }
    else
        std::cout << "\033[31m" << this->name << "\033[0m" << " can't use this !" << std::endl;
}


