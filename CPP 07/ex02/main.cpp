/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:35:38 by root              #+#    #+#             */
/*   Updated: 2023/11/16 09:45:20 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    try
    {   
        std::cout << "\033[1mCreating a, NULL float array\033[0m" << std::endl;
        Array<float> a;
        std::cout << "a size = " << a.size() << std::endl;
        std::cout << std::endl;
        
        std::cout << "\033[1mCreating b, a std::string array of size 20\033[0m" << std::endl;
        Array<std::string> b(20);
        std::cout << "b size = " << b.size() << std::endl;
        b[5] = "Salut";
        b[6] = "3*3 = 9";
        std::cout << "b[5] = " << b[5] << std::endl;
        std::cout << "b[6] = " << b[6] << std::endl;
        std::cout << std::endl;
        
        
        std::cout << "\033[1mCreating c, a std::string array by copy\033[0m" << std::endl;
        Array<std::string> c(b);
        std::cout << "c size = " << c.size() << std::endl;
        std::cout << "c[5] = " << c[5] << std::endl;
        std::cout << "c[6] = " << c[6] << std::endl;
        std::cout << std::endl;
        
        
        std::cout << "\033[1mCreating d and e, int array of size 8 and 10\033[0m" << std::endl;
        Array<int> d(8);
        Array<int> e(10);
        e[0] = 1;
        e[1] = 2;
        e[2] = 3;
        e[3] = 4;
        e[4] = 5;
        std::cout << "\033[1mThen, use the copy assignement operator\033[0m" << std::endl;
        d = e;
        std::cout << "d size = " << d.size() << std::endl;
        for (int i = 0; i < 5; i++)
            std::cout << "d[" << i << "] = " << d[i] << std::endl;
        std::cout << "d[5] = " << b[0] << std::endl;
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << ": \033[0;31mIndex doesn't exist\033[0m" <<'\n';
    }

    // Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];
    // srand(time(NULL));
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     const int value = rand();
    //     numbers[i] = value;
    //     mirror[i] = value;
    // }
    // //SCOPE
    // {
    //     Array<int> tmp = numbers;
    //     Array<int> test(tmp);
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     if (mirror[i] != numbers[i])
    //     {
    //         std::cerr << "didn't save the same value!!" << std::endl;
    //         return 1;
    //     }
    // }
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     numbers[i] = rand();
    // }
    // delete [] mirror;
    return 0;
}