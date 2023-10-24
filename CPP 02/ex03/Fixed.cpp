/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:44:04 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/23 12:45:38 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

						//CONSTRUCTOR

//that converts the fixed-point value to a floating-point value
Fixed::Fixed(const int obj)
{
	// std::cout << "Int constructor called" << std::endl;
	stockFixedPointNumber = obj << stockNumberOfFractionalBits;
}

//that converts the fixed-point value to an integer value.
Fixed::Fixed(const float obj)
{
	// std::cout << "Float constructor called" << std::endl;
	stockFixedPointNumber = roundf((1 << stockNumberOfFractionalBits) * obj);
}

Fixed::Fixed() :stockFixedPointNumber(0)
{
	// std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed&	newFixed)
{ 
	// std::cout << "Copy constructor called" << std::endl;
	*this = newFixed;
}




						//OPERATOR

bool Fixed::operator>(Fixed const & objectToCompare) const
{
	if ( stockFixedPointNumber > objectToCompare.stockFixedPointNumber)
	{
		return (true);
	}
	return (false);
}

bool Fixed::operator<(Fixed const & objectToCompare) const
{
	if ( stockFixedPointNumber < objectToCompare.stockFixedPointNumber )
	{
		return (true);
	}
	return (false);
}

bool Fixed::operator>=(Fixed const & objectToCompare) const
{
	if ( stockFixedPointNumber >= objectToCompare.stockFixedPointNumber)
	{
		return (true);
	}
	return (false);
}

bool Fixed::operator<=(Fixed const & objectToCompare) const
{
	if ( stockFixedPointNumber <= objectToCompare.stockFixedPointNumber)
	{
		return (true);
	}
	return (false);
}

bool Fixed::operator==(Fixed const & objectToCompare) const
{
	if (objectToCompare.stockFixedPointNumber == stockFixedPointNumber)
	{
		return (true);
	}
	return (false);
}

bool Fixed::operator!=(Fixed const & objectToCompare) const
{
	if (objectToCompare.stockFixedPointNumber != stockFixedPointNumber)
	{
		return (true);
	}
	return (false);
}

Fixed  Fixed::operator+(Fixed const & objectToAddition) const
{
	return (Fixed(this->toFloat() + objectToAddition.toFloat()));
}

Fixed  Fixed::operator-(Fixed const & objectToSubstract) const
{
	return (Fixed(this->toFloat() - objectToSubstract.toFloat()));
}

Fixed  Fixed::operator*(Fixed const & objectToMultiply) const
{
	return (Fixed(this->toFloat() * objectToMultiply.toFloat()));
}

Fixed  Fixed::operator/(Fixed const & objectToDivide) const
{
	return (Fixed(this->toFloat() / objectToDivide.toFloat()));
}

//pré-incrémentation
Fixed&	Fixed::operator++()
{
	stockFixedPointNumber +=1;
	return (*this);
}


//pré-décrémentation
Fixed&	Fixed::operator--()
{
	stockFixedPointNumber -=1;
	return (*this);
}


//par convention, on donne un INT factice a l'operateur de post incré pour le distinguer
Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	++(*this);
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	--(*this);
	return (temp);
}

Fixed& Fixed::operator=(Fixed const & objectToCopy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &objectToCopy)
	{
		this->stockFixedPointNumber = objectToCopy.stockFixedPointNumber;
	}
	return (*this);
}

//Affiche sur la sortie OS l'objet Fixed en float
std::ostream&	operator<<(std::ostream& os, const Fixed& objet)
{
	return (os << objet.toFloat());

}



						//FUNCTIONS
// Surcharge de la fonction membre statique min pour les références modifiables
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return ((a.stockFixedPointNumber < b.stockFixedPointNumber) ? a : b);
}
// Surcharge de la fonction membre statique min pour les références constantes
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a.stockFixedPointNumber < b.stockFixedPointNumber) ? a : b);
}
// Surcharge de la fonction membre statique max pour les références modifiables
Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return ((a.stockFixedPointNumber > b.stockFixedPointNumber) ? a : b);
}

// Surcharge de la fonction membre statique max pour les références constantes
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a.stockFixedPointNumber > b.stockFixedPointNumber) ? a : b);
}

//that returns the raw value of the fixed-point value.
int		Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->stockFixedPointNumber);
}

//that sets the raw value of the fixed-point number
void	Fixed::setRawBits( int const raw)
{
	this->stockFixedPointNumber = raw;
}

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



					//DESTRUCTOR

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}