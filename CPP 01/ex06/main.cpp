/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:03:52 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/20 17:49:09 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "\033[0;35mInvalid arguments, please retry and use :" << std::endl;
		std::cout << "DEBUG : INFO : WARNING : ERROR or one other string \033[0m" << std::endl;
		return (0);
	}

	std::string level = argv[1];

	harl.complain(level);
	return (0);
}