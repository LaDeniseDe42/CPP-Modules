/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:32:13 by root              #+#    #+#             */
/*   Updated: 2023/12/06 15:28:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: ./PmergeMe [number]" << std::endl;
        return (1);
    }
    srand(time(NULL));
    PmergeMe pm;
    pm.fillVector(argc -1, argv);
    pm.fillList(argc -1, argv);
    pm.printVector();
    pm.printList();
    std::clock_t start_time = std::clock();
    pm.mergeVec();
    std::clock_t end_time = std::clock();
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Time to merge vector: " << elapsed_time * 1000000 << "ms" << std::endl;
    start_time = std::clock();
    pm.mergeLi();
    end_time = std::clock();
    elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Time to merge list: " << elapsed_time * 1000000 << "ms" << std::endl;
    return (0);
}