/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:06:56 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/23 10:02:28 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


//Pour effectuer correctement la conversion en un nombre à virgule flottante,
//il est nécessaire de diviser le nombre à virgule fixe par une valeur qui
//représente le poids des bits fractionnaires.
//Cette valeur est déterminée par une puissance de 2 en fonction de la quantité de bits fractionnaires.

//convertis un nombre a virgule fixe en float
float	Fixed::toFloat( void ) const
{
	//1 << stockNumber.. permet de calculer la valeur de puissance de 2
	// en fonction de la quantité de bits de stockFixed
	return ((float)(stockFixedPointNumber / (float)(1 << stockNumberOfFractionalBits)));
}

//convertis un nombre fixe en int
//supprime les bits réservés pour la partie fractionnaire
//du nombre et conserve uniquement la partie entière.
int		Fixed::toInt( void ) const
{
	return (stockFixedPointNumber >> stockNumberOfFractionalBits);
}

//Affiche sur la sortie OS(sortie standard) l'objet Fixed en float
std::ostream&	operator<<(std::ostream& os, const Fixed& objet)
{
	return (os << objet.toFloat());

}

//convertit l'entier en une représentation à virgule fixe
//en le décalant vers la gauche par le nombre de bits fractionnaires
Fixed::Fixed(const int obj)
{
	std::cout << "Int constructor called" << std::endl;
	stockFixedPointNumber = obj << stockNumberOfFractionalBits;
}

//convertit le nombre à virgule flottante en une représentation à virgule fixe
Fixed::Fixed(const float obj)
{
	std::cout << "Float constructor called" << std::endl;
	// roundf() permet d'arrondir un nombre à virgule flottante vers l'entier l plus proche
	stockFixedPointNumber = roundf((1 << stockNumberOfFractionalBits) * obj);
}


//default constructor
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