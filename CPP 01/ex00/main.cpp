/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:21:07 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/18 15:02:04 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::string buffStack;
	std::string	buffHeap;
	Zombie		zombie;
	Zombie		*zombieH;
	

	std::cout << "\033[32mPauvre fou, tu viens de donner vie a : ";
	std::cout << "\033[35mPatrick le papa Zombie du main\033[0m" << std::endl;
	std::cout << "\033[32mNow, it's your responsability to feed him" << std::endl;
	std::cout << std::endl;
	std::cout << "Name the Zombie for the stack 🧟‍♂️ :" << std::endl;
	std::cout << "=>  \033[0m";

	if (!std::getline(std::cin, buffStack) || buffStack.length() <= 0 || (buffStack.find('\t') != std::string::npos))
	{
		if ((buffStack.find('\t') != std::string::npos))
		{
			std::cout << "If you cant name a Zombie, i do the job for you" << std::endl;
			zombie.randomChump("Caroline");
		}
		else if (buffStack.length() <= 0)
		{
			std::cout << "If you cant name a Zombie, i do the job for you" << std::endl;
			zombie.randomChump("Caroline");
		}
		else
		{
			std::cout << "Error :invalid name" << std::endl;
			return (0);
		}
	}
	else
		zombie.randomChump(buffStack);

	std::cout << "\033[32m Name the Zombie for the heap 🧟‍♂️ :" << std::endl;
	std::cout << "=>  \033[0m";
	if (!std::getline(std::cin, buffHeap) || buffHeap.length() <= 0 || (buffHeap.find('\t') != std::string::npos))
	{
		if ((buffHeap.find('\t') != std::string::npos))
		{
			std::cout << "If you cant name a Zombie, i do the job for you" << std::endl;
			zombieH	= zombie.newZombie("Nathan");
			zombieH->announce();
			delete zombieH;
		}
		else if (buffHeap.length() <= 0)
		{
			std::cout << "If you cant name a Zombie, i do the job for you" << std::endl;
			zombieH	= zombie.newZombie("Ali");
			zombieH->announce();
			delete zombieH;
		}
		else
		{
			std::cout << "Error: invalid name" << std::endl;
			return (0);
		}
	}
	else
	{
		zombieH	= zombie.newZombie(buffHeap);
		zombieH->announce();
		delete zombieH;
	}
	return (0);
}