/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:07:49 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/19 16:49:35 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

//CONSTRUCTEURS

//default
MateriaSource::MateriaSource()
{
	std::cout << "\033[33mMateriaSource default constructor called \033[0m " << std::endl;
    for (int i = 0 ; i < 4; i++)
    {
        this->memory[i] = NULL;
    }

}

//cpy constructor
MateriaSource::MateriaSource(const MateriaSource&	newMateriaSource)
{ 
	std::cout << "\033[33mMateriaSource Copy constructor called\033[0m " << std::endl;
    for (int i = 0 ; i < 4; i++)
    {
        this->memory[i] = NULL;
    }
	*this = newMateriaSource;
    
}

//Copy assignment operator
MateriaSource& MateriaSource::operator=(MateriaSource const & objectToCopy)
{
	std::cout << "\033[33mMateriaSource Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
		for (int i = 0 ; i < 4; i++)
        {
            this->memory[i] = NULL;
        }
	}
	return (*this);
}

//destructor
MateriaSource::~MateriaSource()
{
	std::cout << "Hey you i'm \033[36mMateriaSource\033[0m destructor" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        if (memory[i])
            delete memory[i];
    }
}


//FUNCTIONS

//Copies the Materia passed as a parameter and store it in memory so it can be cloned
//later. Like the Character, the MateriaSource can know at most 4 Materias. They
//are not necessarily unique.
void MateriaSource::learnMateria(AMateria* bookOfMagic)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->memory[i] == NULL && i < 4)
        {
            this->memory[i] = bookOfMagic;
            std::cout << "You learn a new magic spell : \033[35m" << bookOfMagic->getType()  << "\033[0m" << std::endl;
            return ;
        }
        if (i == 3)
        {
            delete bookOfMagic;
            std::cout << "your brain is full, you can't learn more" << std::endl;
            return ;
        }
    }
}


//Returns a new Materia. The latter is a copy of the Materia previously learned by
//the MateriaSource whose type equals the one passed as parameter. Returns 0 if
//the type is unknown
AMateria* MateriaSource::createMateria(std::string const & type)
{
     for (int i = 0; i < 4; i++)
    {
        if (memory[i] && memory[i]->getType() == type)
        {
            std::cout << "You create a new item : " << type << std::endl;
            return (memory[i]->clone());
        }
    
    }
    return 0;
}