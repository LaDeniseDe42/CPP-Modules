/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:22:48 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/21 12:53:00 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
try
{
std::srand(std::time(0));

std::cout << "\033[1mTest 1\033[0m" << std::endl;
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
sp.printValue();
std::cout << "\033[0;35mThe shortest Span of sp is : " << sp.shortestSpan() << "\033[0m" << std::endl;
std::cout << "\033[0;35mThe longest Span of sp is : " << sp.longestSpan() << "\033[0m" << std::endl;
std::cout << std::endl;

std::cout << "\033[1mTest 2 et 3\033[0m" << std::endl;
Span test2;
Span test3(15);
test2 = test3;
test2.addNumber(10);
test2.addNumber(20);
test2.addNumber(30);
test2.addNumber(40);
test2.addNumber(50);
test2.printValue();
std::cout << "\033[0;35mThe shortest Span of test2 is : " << test2.shortestSpan() << "\033[0m" << std::endl;
std::cout << "\033[0;35mThe longest Span of test2 is : " << test2.longestSpan() << "\033[0m" << std::endl;
std::cout << std::endl;

std::cout << "\033[1mTest 4\033[0m" << std::endl;
Span test4(test2);
test4.addNumber(66);
test4.addNumber(77);
test4.addNumber(88);
test4.addNumber(99);
test4.addNumber(100);
test4.printValue();
std::cout << "\033[0;35mThe shortest Span of test4 is : " << test4.shortestSpan() << "\033[0m" << std::endl;
std::cout << "\033[0;35mThe longest Span of test4 is : " << test4.longestSpan() << "\033[0m" << std::endl;

std::cout << std::endl;
std::cout << "\033[1mTest 5\033[0m" << std::endl;
Span test5(10000);
for(int i = 0; i < 10000; i++)
{
    int randomNumber = std::rand() % 10000;
    test5.addNumber(randomNumber);
}
//test5.printValue();
std::cout << "\033[0;35mThe shortest Span of test4 is : " << test5.shortestSpan() << "\033[0m" << std::endl;
std::cout << "\033[0;35mThe longest Span of test4 is : " << test5.longestSpan() << "\033[0m" << std::endl;

}
catch (std::exception &e)
{
    std::cerr << e.what() << '\n';
}
return 0;
}