/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:32:34 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/07 09:42:15 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int argc, char **argv)
{
	PhoneBook	book;
	std::string buff;
	(void)argv;

	if (argc != 1)
		return (0);
	else
	{
		book.helloPhone();
		while (1)
		{
			std::cout << std::endl;
			std::cout << "=>  ";
			if (!std::getline(std::cin, buff))
				break ;
			if (buff == "ADD")
				book.addContact();
			else if (buff == "SEARCH")
				book.searchContact();
			else if (buff == "EXIT")
				break ;
			else
				std::cout << "Use your brain and put correct instruction ";
		}

	}
	return (0);
}