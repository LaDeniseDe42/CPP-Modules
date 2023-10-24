/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:44:56 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/24 15:28:18 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;


	Fixed test(5);
	Fixed test2(10);
	Fixed test3(test/test2);
	Fixed test4(test3 - test2);
	std::cout << "test / test2 = " << test3 << std::endl;
	std::cout << "test3 - test2 = " << test4 << std::endl;

	std::cout << Fixed::min( a, b ) << std::endl;
	if ( test <= test2)
		std::cout << "GOOD" << std::endl;
	else
		std::cout << "NOT GOOD" << std::endl;
	return (0);
}
