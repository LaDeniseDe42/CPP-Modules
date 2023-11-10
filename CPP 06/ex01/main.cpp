/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:14:14 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/10 09:58:40 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "Data.hpp"
#include "Serializer.hpp"


//on utilise le reinerpret_cast pour effectuer des conversions entre
// des pointeurs ou des références de types sans rapport, comme les conversions de pointeurs vers des entiers.

int main()
{
    Data dataObject(42, "Cette phrase ne change rien au test.");

    uintptr_t serializedData = Serializer::serialize(&dataObject);
    Data* deserializedData = Serializer::deserialize(serializedData);
    if (deserializedData == &dataObject)
    {
        std::cout << &dataObject << std::endl;
        std::cout << deserializedData << std::endl;
        std::cout << "Test réussi : les adresses sont les memes." << std::endl;
    }
    else
    {
        std::cout << &dataObject << std::endl;
        std::cout << deserializedData << std::endl;
        std::cout << "Test échoué : les adresses ne sont pas les memes." << std::endl;
    }


    Data dataObject2;

    uintptr_t test2 = Serializer::serialize(&dataObject2);
    Data* detest2 = Serializer::deserialize(test2);
    if (detest2 == &dataObject2)
    {
        std::cout << &dataObject2 << std::endl;
        std::cout << detest2 << std::endl;
        std::cout << "Test réussi : les adresses sont les memes." << std::endl;
    }
    else
    {
        std::cout << &dataObject2 << std::endl;
        std::cout << detest2 << std::endl;
        std::cout << "Test échoué : les adresses ne sont pas les memes." << std::endl;
    }
    
    return (0);
}