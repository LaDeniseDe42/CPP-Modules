/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:07:28 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/23 09:27:21 by qdenizar         ###   ########.fr       */
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
	Fixed();//default constructor
	Fixed(const int obj);
	Fixed(const float obj);
	Fixed(const Fixed& newFixed);//cpy constructor
	~Fixed();//destructor

	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
	Fixed&  operator=(Fixed const & objectToCopy); //cpy operator
};

std::ostream&	operator<<(std::ostream& os, const Fixed& objet);

#endif