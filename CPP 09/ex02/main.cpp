/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:32:13 by root              #+#    #+#             */
/*   Updated: 2023/12/12 15:31:57 by qdenizar         ###   ########.fr       */
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
    if (pm.verifArg(argc -1, argv) == 1)
    {
        std::cout << "ERROR: I SAY  POSITIVE NUMBER" << std::endl;
        return (1);
    }
    std::clock_t start_time = std::clock();
    pm.fillVector(argc -1, argv);
    pm.printVector(argc -1);
    pm.mergeVec(argc -1);
    std::clock_t end_time = std::clock();
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of  " << argc -1 << " elements with std::vector : " << elapsed_time * 1000000 << " microS" << std::endl;


    
    start_time = std::clock();
    pm.filldeque(argc -1, argv);
    pm.printdeque(argc -1);
    pm.mergeDe( argc -1);
    end_time = std::clock();
    elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of  " << argc -1 << " elements with std::deque : " << elapsed_time * 1000000 << " microS" << std::endl;
    return (0);
}