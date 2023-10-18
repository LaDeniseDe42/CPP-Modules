/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:36:14 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/26 13:26:13 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() :stockFixedPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed&	newFixed) :stockFixedPointNumber(newFixed.stockFixedPointNumber)
{ 
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed& objectToCopy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &objectToCopy)
	{
		this->stockFixedPointNumber = objectToCopy.stockFixedPointNumber;
	}
	return (*this);
}

//that returns the raw value of the fixed-point value.
int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->stockFixedPointNumber);
}


//that sets the raw value of the fixed-point number
void	Fixed::setRawBits( int const raw)
{
	this->stockFixedPointNumber = raw;
}