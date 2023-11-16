/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:17:17 by root              #+#    #+#             */
/*   Updated: 2023/11/15 12:07:50 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"


int main() {
    // Exemple avec un tableau d'int
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]); //taille totale /taille d'un élément = nombre d'éléments dans le tableau.

    std::cout << "\033[4mInteger array elements:\033[0;35m ";
    ::iter(intArray, intArrayLength, ::printArrayValue<int>);
    std::cout << "\033[0m" << std::endl;

    // Exemple avec un tableau de doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "\033[4mDouble array elements:\033[0;35m ";
    ::iter(doubleArray, doubleArrayLength, ::printArrayValue<double>);
    std::cout << "\033[0m" << std::endl;

    // Exemple avec un tableau de float
    float floatArray[] = {49.13f, 17.0f, 29.03f, 18.12f, 19.94f};
    size_t floatArrayLength = sizeof(floatArray) / sizeof(floatArray[0]);

    std::cout << "\033[4mfloat array elements:\033[0;35m ";
    ::iter(floatArray, floatArrayLength, ::printArrayValue<float>);
    std::cout << "\033[0m" << std::endl;
    
    // Exemple avec un tableau de strings
    std::string stringArray[] = {"Raspoutine", "bidet", "grain de sable", "burger"};
    size_t stringArrayLength = sizeof(stringArray) / sizeof(stringArray[0]);
    
    std::cout << "\033[4mString array elements:\033[0;35m ";
    ::iter(stringArray, stringArrayLength, ::printArrayValue<std::string>);
    std::cout << "\033[0m" << std::endl;


    // Exemple avec un tableau de char
    char charArray[] = {'Q', 'u', 'e', 'n', 't', 'i', 'n'};
    size_t charArrayLength = sizeof(charArray) / sizeof(charArray[0]);
    
    std::cout << "\033[4mchar array elements:\033[0;35m ";
    ::iter(charArray, charArrayLength, ::printArrayValue<char>);
    std::cout << "\033[0m" << std::endl;

    // Exemple avec un tableau de bool
    bool boolArray[] = {true, false, true, false, true};
    size_t boolArrayLength = sizeof(boolArray) / sizeof(boolArray[0]);

    std::cout << "\033[4mbool array elements:\033[0;35m ";
    ::iter(boolArray, boolArrayLength, ::printArrayValue<bool>);
    std::cout << "\033[0m" << std::endl;

    // Exemple avec un tableau de d'adresse
    int *intPtrArray[] = {&intArray[0], &intArray[1], &intArray[2], &intArray[3], &intArray[4]};
    size_t intPtrArrayLength = sizeof(intPtrArray) / sizeof(intPtrArray[0]);
    
    std::cout << "\033[4mint pointer array elements:\033[0;35m ";
    ::iter(intPtrArray, intPtrArrayLength, ::printArrayValue<int *>);
    std::cout << "\033[0m" << std::endl;
  
    
    return 0;
}
