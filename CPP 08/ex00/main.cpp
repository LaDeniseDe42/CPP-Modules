/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:41:31 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/17 09:11:56 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <vector> //Un tableau dynamique qui peut être redimensionné automatiquement.
#include <list>//Une liste doublement chaînée.
#include <set>//Un ensemble ordonné d'éléments uniques
#include <iterator>//Fournit des classes et des fonctions pour travailler avec des itérateurs.
#include <functional>//Fournit des objets de fonction et des opérations sur les fonctions, notamment des foncteurs.
#include <algorithm>//Fournit de nombreux algorithmes génériques tels que sort, find, transform, etc.


#include "easyfind.hpp"

int main() {
    // Utilisation avec std::vector
   std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    easyfind(vec, 3);

    // Utilisation avec std::list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    easyfind(lst, 25);

    // Utilisation avec std::set
    std::set<int> s;
    s.insert(100);
    s.insert(200);
    s.insert(300);
    s.insert(400);
    s.insert(500);
    easyfind(s, 200);

    return 0;
}