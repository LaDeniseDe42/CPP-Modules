/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:17:03 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/08 13:09:41 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
    private:
        //Orthodox Canonical Serializer
        Serializer();//default constructor
        ~Serializer();//destructor
        Serializer(const Serializer&	newSerializer); //cpy constructor
        Serializer& operator=(Serializer const & objectToCopy); //Copy assignment operator
        
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t value);      
};