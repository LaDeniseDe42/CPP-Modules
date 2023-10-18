/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:06:56 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/27 10:29:32 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//convertis un nombre a virgule fixe en float
float	Fixed::toFloat( void ) const
{
	return ((float)(stockFixedPointNumber / (float)(1 << stockNumberOfFractionalBits)));
}

//convertis un nombre a virgule fixe en int
int		Fixed::toInt( void ) const
{
	return (stockFixedPointNumber >> stockNumberOfFractionalBits);
}

//Affiche sur la sortie OS l'objet Fixed en float
std::ostream&	operator<<(std::ostream& os, const Fixed& objet)
{
	return (os << objet.toFloat());

}

//that converts the fixed-point value to a floating-point value
Fixed::Fixed(const int obj)
{
	std::cout << "Int constructor called" << std::endl;
	stockFixedPointNumber = obj << stockNumberOfFractionalBits;
}

//that converts the fixed-point value to an integer value.
Fixed::Fixed(const float obj)
{
	std::cout << "Float constructor called" << std::endl;
	stockFixedPointNumber = roundf((1 << stockNumberOfFractionalBits) * obj);
}

Fixed::Fixed() :stockFixedPointNumber(0)
{
	std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed&	newFixed)
{ 
	std::cout << "Copy constructor called" << std::endl;
	*this = newFixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const & objectToCopy)
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