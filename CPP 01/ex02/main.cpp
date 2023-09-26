/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:58:53 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/19 10:39:17 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>

int	main()
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string		*brainPtr = &brain;
	std::string&	refBrain = brain;

	std::cout << "\033[31mThe memory address of brain is : \033[32m" << &brain << std::endl;
	std::cout << "\033[31mThe memory address held by brainPtr is : \033[32m" << brainPtr << std::endl;
	std::cout << "\033[31mThe memory address held by refBrain is : \033[32m" << &refBrain << std::endl;

	std::cout << "\033[31mThe value of brain is : \033[32m" << brain << std::endl;
	std::cout << "\033[31mThe value pointed by brainPtr is : \033[32m" << *brainPtr << std::endl;
	std::cout << "\033[31mThe value pointed by refBrain is : \033[32m" << refBrain << std::endl;

	return (0);
}