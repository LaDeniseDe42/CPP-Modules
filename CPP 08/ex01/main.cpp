/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:22:48 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/20 15:55:38 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"



int main()
{
try
{
std::cout << "Test 1" << std::endl;
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << "The shortest Span of sp is : " << sp.shortestSpan() << std::endl;
std::cout << "The longest Span of sp is : " << sp.longestSpan() << std::endl;
std::cout << std::endl;

std::cout << "Test 2 et 3" << std::endl;
Span test2;
Span test3(15);
test2 = test3;
test2.addNumber(10);
test2.addNumber(20);
test2.addNumber(30);
test2.addNumber(40);
test2.addNumber(50);
std::cout << "The shortest Span of test2 is : " << test2.shortestSpan() << std::endl;
std::cout << "The longest Span of test2 is : " << test2.longestSpan() << std::endl;
std::cout << std::endl;

std::cout << "Test 4" << std::endl;
Span test4(test3);
test4.addNumber(10);
test4.addNumber(20);
test4.addNumber(30);
test4.addNumber(40);
test4.addNumber(50);
std::cout << test4[0] << std::endl;
std::cout << "The shortest Span of test4 is : " << test2.shortestSpan() << std::endl;
std::cout << "The longest Span of test4 is : " << test2.longestSpan() << std::endl;
}
catch (std::exception &e)
{
    std::cerr << e.what() << '\n';
}
return 0;
}