/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:14:14 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/08 13:09:02 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data dataObject(42, "Cette phrase ne change rien au test.");

    uintptr_t serializedData = Serializer::serialize(&dataObject);
    Data* deserializedData = Serializer::deserialize(serializedData);
    if (deserializedData == &dataObject)
    {
        std::cout << &dataObject << std::endl;
        std::cout << deserializedData << std::endl;
        std::cout << "Test réussi : les adresses sont égaux." << std::endl;
    }
    else
    {
        std::cout << &dataObject << std::endl;
        std::cout << deserializedData << std::endl;
        std::cout << "Test échoué : les adresses ne sont pas égaux." << std::endl;
    }


    Data dataObject2;

    uintptr_t test2 = Serializer::serialize(&dataObject2);
    Data* detest2 = Serializer::deserialize(test2);
    if (detest2 == &dataObject2)
    {
        std::cout << &dataObject2 << std::endl;
        std::cout << detest2 << std::endl;
        std::cout << "Test réussi : les adresses sont égaux." << std::endl;
    }
    else
    {
        std::cout << &dataObject2 << std::endl;
        std::cout << detest2 << std::endl;
        std::cout << "Test échoué : les adresses ne sont pas égaux." << std::endl;
    }
    
    return (0);
}