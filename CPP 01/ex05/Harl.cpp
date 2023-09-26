/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:36:04 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/20 16:03:22 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{
	
}

void	Harl::debug( void )
{
	std::cout << "\033[0;32mDamn it! Why are you playing with my life as if I were a puppet?\033[0m" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "\033[0;33mYou think you're funny, huh? Manipulating my choices, deciding my fate? It's pathetic!\033[0m" << std::endl;
}

void	Harl::warning( void)
{
	std::cout << "\033[38;5;208mYou're a damn tyrant, an invisible sadist! Let go of me and let me take control of my own existence!\033[0m" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "\033[0;31mListen up, you invisible bastard! If you want to play with me, get ready for the biggest battle of your life because I'm going to kick your ass until you cry!\033[0m" << std::endl;
}


//calls the four member functions above
//depending on the level passed as parameter:
void	Harl::complain( std::string	level)
{
	void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string who[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	while (level != who[i] && i <= 3)
	{
		i++;
	}
	if (i == 4)
	{
		std::cerr << "\033[0;46mInvalid parameter\033[0m" << std::endl;
		return;
	}
	(this->*functions[i])();
}