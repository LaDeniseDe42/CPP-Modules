/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:50:51 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/19 10:58:14 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
    private:

    AMateria* memory[4];

    public:
    
    //Orthodox Canonical Form
    MateriaSource(); //default constructor
    MateriaSource(const MateriaSource&	newMateriaSource); //cpy constructor
    MateriaSource& operator=(MateriaSource const & objectToCopy); //Copy assignment operator
    ~MateriaSource();//destructor


    //Functions
    void learnMateria(AMateria* bookOfMagic);
    AMateria* createMateria(std::string const & type);
};


#endif