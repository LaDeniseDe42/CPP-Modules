/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:17:17 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/08 12:42:56 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//CONSTRUCTEURS

//default
Serializer::Serializer()
{
	//std::cout << "\033[33mSerializer default constructor called \033[0m " << std::endl;
}

//cpy constructor
Serializer::Serializer(const Serializer&	newSerializer)
{ 
	//std::cout << "\033[33mSerializer Copy constructor called\033[0m " << std::endl;
	*this = newSerializer;
}


//Copy assignment operator
Serializer& Serializer::operator=(Serializer const & objectToCopy)
{
	//std::cout << "\033[33mSerializer Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
	}
	return (*this);
}

//Function members

//It takes a pointer and converts it to the unsigned integer type uintptr_t
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t reinterpretPtr = reinterpret_cast<uintptr_t>(ptr);
	return (reinterpretPtr);
}

//It takes an unsigned integer parameter and converts it to a pointer to Data.
Data* Serializer::deserialize(uintptr_t value)
{
	void *reinterpretvalue= reinterpret_cast<void *>(value);
	return (reinterpret_cast<Data *>(reinterpretvalue));
}

//DESTRUCTEUR

Serializer::~Serializer()
{
	//std::cout << "\033[33mSerializer destructor called\033[0m " << std::endl;
}