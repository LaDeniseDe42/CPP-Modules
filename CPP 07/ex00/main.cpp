/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:16:59 by root              #+#    #+#             */
/*   Updated: 2023/11/15 12:08:04 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main( void )
{
    int a = 2;
    int b = 3;
    std::cout << "\033[0;32m" << "a = " << a << ", b = " << b << std::endl;
    ::swap( a, b );
    std::cout << "After swap a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::cout  << "\033[0m" << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "\033[0;33m" << "c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    std::cout  << "\033[0m" << std::endl;
    
    char e = 'a';
    char f = 'A';
    std::cout << "\033[0;34m" << "e = " << e << ", f = " << f << std::endl;
    ::swap(e, f);
    std::cout << "After swap e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
    std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
    std::cout  << "\033[0m" << std::endl;

    float g = 42.42f;
    float h = 21.21f;
    std::cout << "\033[0;35m" << "g = " << g << ", h = " << h << std::endl;
    ::swap(g, h);
    std::cout << "After swap g = " << g << ", h = " << h << std::endl;
    std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
    std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;
    std::cout  << "\033[0m" << std::endl;

    double i = 42.42;
    double j = 21.21;
    std::cout << "\033[0;36m" << "i = " << i << ", j = " << j << std::endl;
    ::swap(i, j);
    std::cout << "After swap i = " << i << ", j = " << j << std::endl;
    std::cout << "min( i, j ) = " << ::min( i, j ) << std::endl;
    std::cout << "max( i, j ) = " << ::max( i, j ) << std::endl;
    std::cout  << "\033[0m" << std::endl;
    
    return 0;
}