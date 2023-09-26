/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:05:00 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/19 09:57:54 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::string		buffName;
	std::string		buffN;
	size_t			nbZombie;
	Zombie			*zomb = NULL;

	std::cout << "\033[32mHelo, Patrick is back and he asked your help because unfortunely, Patrick eated is own brain" <<std::endl;
	std::cout << "Please, how much zombies do you want in the horde ?";
	std::cout << std::endl << "Give me a positive number: \033[0m";
	if (!std::getline(std::cin, buffN) || buffN.length() <= 0 || (buffN.find('\t') != std::string::npos))
	{
		std::cout << " \033[32mif you cant give me a number, i will choose for you ' 10 '\033[0m" << std::endl;
		nbZombie = 10;
	}
	else
	{
		size_t i = 0;
		while (buffN[i])
		{
			if (!std::isdigit(buffN[i]))
			{
				std::cout << "\033[32mthis is not a digit\033[0m" << std::endl;
				break ;
			}
			i++;
		}
		if (buffN.length() == i)
		{
			nbZombie = std::atoi(buffN.c_str());
			if (nbZombie >= 1000)
			{
				std::cout << "\033[32mYou want to break this Mac ??" << std::endl;
				std::cout << "ok i choose for you ' 30 '\033[0m" << std::endl;
				nbZombie = 30;
			}
		}
		else
		{
			std::cout << "\033[32mIf you cant give me a number, i will choose for you ' 10 '\033[0m" << std::endl;
			nbZombie = 10;
		}
	}

	std::cout << "\033[32mNow, give a name for this Horde :\033[0m";
	if (!std::getline(std::cin, buffName) || buffName.length() <= 0 || (buffName.find('\t') != std::string::npos) || buffName.length() >= 20)
	{
		if (buffName.length() <= 0 || (buffName.find('\t') != std::string::npos) || buffName.length() >= 20)
		{
			std::cout << "\033[32mthis is not a valid name, i will choose for you ' Yorrick'Horde '\033[0m" << std::endl;
			buffName = "Yorrick'Horde";
			zomb = zomb->zombieHorde(nbZombie, buffName);
			size_t	j = 0;
			while (j < nbZombie)
			{
				zomb[j].announce();
				j++;
			}
		}
	}
	else
	{
		zomb = zomb->zombieHorde(nbZombie, buffName);
		size_t	k = 0;
		while (k < nbZombie)
		{
			zomb[k].announce();
			k++;
		}
	}
	delete [] zomb;
}