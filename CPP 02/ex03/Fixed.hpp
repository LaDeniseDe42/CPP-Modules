/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:44:25 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/29 11:08:38 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>


class Fixed
{
private:
	int					stockFixedPointNumber;
	static const int	stockNumberOfFractionalBits = 8;
public:
	Fixed();
	Fixed(const int obj);
	Fixed(const float obj);
	Fixed(const Fixed& newFixed);
	~Fixed();

	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw);

	static	Fixed&	min(Fixed& a, Fixed& b);
	static	const Fixed&	min(const Fixed& a, const Fixed& b);
	static	Fixed&	max(Fixed& a, Fixed& b);
	static	const Fixed&	max(const Fixed& a, const Fixed& b);

	Fixed&  operator=(Fixed const & objectToCopy);
	bool	operator>(Fixed const & objectToCompare) const;
	bool	operator<(Fixed const & objectToCompare) const;
	bool	operator>=(Fixed const & objectToCompare) const;
	bool	operator<=(Fixed const & objectToCompare) const;
	bool	operator==(Fixed const & objectToCompare) const;
	bool	operator!=(Fixed const & objectToCompare) const;

	Fixed  operator+(Fixed const & objectToAddition) const;
	Fixed  operator-(Fixed const & objectToSubstract) const;
	Fixed  operator*(Fixed const & objectToMultiply) const;
	Fixed  operator/(Fixed const & objectToDivide) const;
	
	Fixed&	operator++();
	Fixed&	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);


};

std::ostream&	operator<<(std::ostream& os, const Fixed& objet);

#endif