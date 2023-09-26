/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:36:01 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/21 14:44:49 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
private:
	int					stockFixedPointNumber;
	static const int	stockNumberOfFractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed& newFixed);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
	Fixed&  operator=(Fixed& objectToCopy);
};


#endif