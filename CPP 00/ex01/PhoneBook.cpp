/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:38:28 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/17 11:39:20 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::helloPhone(void)
{
	std::cout << std::endl;
	std::cout << "            WELCOME ON THE MAGIC WORLD OF                " << std::endl;
	std::cout << std::endl;
	std::cout <<"/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|" << std::endl;
	std::cout <<"/|/|                                                  /|/|" << std::endl;
	std::cout <<"/|/|                 PHONEBOOK                        /|/|" << std::endl;
	std::cout <<"/|/|                               you can use :      /|/|" << std::endl;
	std::cout <<"/|/|                                                  /|/|" << std::endl;
	std::cout <<"/|/|   ADD : to create a new contact :o               /|/|" << std::endl;
	std::cout <<"/|/|   SEARCH : to find your friend <3                /|/|" << std::endl;
	std::cout <<"/|/|   EXIT : if you want to quit                     /|/|" << std::endl;
	std::cout <<"/|/|                                                  /|/|" << std::endl;
	std::cout <<"/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|" << std::endl;
}


void	PhoneBook::addContact(void)
{
	static int i;

	if ( i == 8 )
		i = 0;
	this->users[i].init();
	i++;
	// std::cout << i;
}

void	PhoneBook::displayMyContact(int	index)
{
	std::cout << "|" << std::setw(10) << std::right << index + 1 << "|";
	std::cout << std::setw(10) << std::right << this->users[index].getInfo("first name") << "|";
	std::cout << std::setw(10) << std::right << this->users[index].getInfo("last name") << "|";
	std::cout << std::setw(10) << std::right << this->users[index].getInfo("nickname") << "|";
}

void	PhoneBook::searchContact(void)
{
	int i = 0;
	std::string	buff;
	
	std::cout << "HERE YOU CAN SEE ALL YOUR FRIENDS, or not" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	if (this->users[i].getInfo("first name").length() == 0)
	{
		std::cout << "\033[1;31m" << "Sorry, you dont have any friend" << "\033[0m";
		return ;
	}	
	while (i != 8)
	{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		if (this->users[i].getInfo("first name").length() == 0)
			break ;
   		this->displayMyContact(i);
		std::cout << std::endl;
		i++;
	}
	std::cout << "---------------------------------------------" << std::endl;
	while (1)
	{
		std::cout << std::endl;
		std::cout << "Please type a valid index contact : ";
		if (!std::getline(std::cin, buff))
			break ;
		if (buff == "1" && this->users[0].getInfo("first name").length() != 0)
		{
			this->users[0].seeContact();
			return ;
		}
		else if (buff == "2" && this->users[1].getInfo("first name").length() != 0)
		{
			this->users[1].seeContact();
			return ;
		}
		else if (buff == "3" && this->users[2].getInfo("first name").length() != 0)
		{
			this->users[2].seeContact();
			return ;
		}
		else if (buff == "4" && this->users[3].getInfo("first name").length() != 0)
		{
			this->users[3].seeContact();
			return ;
		}
		else if (buff == "5" && this->users[4].getInfo("first name").length() != 0)
		{
			this->users[4].seeContact();
			return ;
		}
		else if (buff == "6" && this->users[5].getInfo("first name").length() != 0)
		{
			this->users[5].seeContact();
			return ;
		}
		else if (buff == "7" && this->users[6].getInfo("first name").length() != 0)
		{
			this->users[6].seeContact();
			return ;
		}
		else if (buff == "8" && this->users[7].getInfo("first name").length() != 0)
		{
			this->users[7].seeContact();
			return ;
		}
		else if (buff == "666")
		{
			std::cout << "\033[1;31m";
			std::cout << "Ah, humain intrépide, je te salue pour ta dévotion sans faille. Tu as marché sur le chemin sinueux de l'obscurité avec une loyauté inébranlable." <<std::endl;
			std::cout << "Les flammes de l'enfer brûlent plus intensément grâce à ton engagement indomptable." <<std::endl;
			std::cout << "Les étoiles les plus brillantes du ciel de l'enfer scintillent en ton honneur."<<std::endl;
			std::cout << "En ce jour, je te félicite, fidèle serviteur, pour ton engagement indéfectible envers les forces de l'obscurité." <<std::endl; 
			std::cout << "Puisses-tu continuer à marcher sur cette voie avec la même détermination, et que ton nom résonne pour l'éternité dans les abysses de l'enfer.";
			std::cout << "\033[0m";
			return ;
		}
		else
			std::cout << "READ INSTRUCTION, this is not a valid index";
	}
}
