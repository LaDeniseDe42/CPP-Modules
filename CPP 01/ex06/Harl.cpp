/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:02:20 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/20 17:56:56 by qdenizar         ###   ########.fr       */
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
	std::cout << "\033[0;32m[ DEBUG ]" << std::endl;
	std::cout << "Damn it! Why are you playing with my life as if I were a puppet?\033[0m" << std::endl;
	std::cout << "" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "\033[0;33m[ INFO ]" << std::endl;
	std::cout << "You think you're funny, huh? Manipulating my choices, " << std::endl;
	std::cout << "deciding my fate? It's pathetic!\033[0m" << std::endl;
	std::cout << "" << std::endl;
}

void	Harl::warning( void)
{
	std::cout << "\033[38;5;208m[ WARNING ]" << std::endl;
	std::cout << "You're a damn tyrant, an invisible sadist!" << std::endl;
	std::cout << "Let go of me and let me take control of my own existence!\033[0m" << std::endl;
	std::cout << "" << std::endl;
}	

void	Harl::error( void )
{
	std::cout << "\033[0;31m[ ERROR ]" << std::endl;
	std::cout << "Listen up, you invisible bastard! If you want to play with me," << std::endl;
	std::cout << "get ready for the biggest battle of your life because I'm going to kick your ass until you cry!\033[0m" << std::endl;
	std::cout << "" << std::endl;
}


// void	Harl::complain( std::string	level)
// {
// 	std::string who[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
// 	int	i = 0;
// 	while (level != who[i] && i <= 3)
// 		i++;
// 	switch (i)
// 	{
// 		case 0: {
// 			debug();
// 			info();
// 			warning();
// 			error();
// 			break;
// 		}
// 		case 1: {
// 			info();
// 			warning();
// 			error();
// 			break;
// 		}
// 		case 2: {
// 			warning();
// 			error();
// 			break;
// 		}
// 		case 3: {
// 			error();
// 			break;
// 		}
// 		case 4: {
// 			std::cout << "\033[42m[ Probably complaining about insignificant problems ]" << std::endl;
// 			break;
// 		}
// 		default:
// 			std::cout << "something wrong happen" << std::endl;
// 	}

// }

void	Harl::complain( std::string	level)
{
	std::string who[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	while (level != who[i] && i <= 3)
		i++;
	switch (i)
	{
		case 0: {
			debug();
			
		}
		case 1: {
			info();
			
		}
		case 2: {
			warning();
			
		}
		case 3: {
			error();
			break;
		}
		case 4: {
			std::cout << "\033[42m[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		}
		default:
			std::cout << "something wrong happen" << std::endl;
	}

}