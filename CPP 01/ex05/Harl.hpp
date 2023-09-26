/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:35:52 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/20 16:03:20 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>


class	Harl
{
	private:
	
		void	debug( void );
		void	info( void );
		void	warning( void);
		void	error( void );

	public:
	
		Harl();
		~Harl();
		void	complain( std::string	level);
	
};

#endif