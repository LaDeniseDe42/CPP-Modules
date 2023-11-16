/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:38:55 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/15 15:39:28 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact()
{
	return;
}

Contact::~Contact()
{
	return;
}

void	Contact::seeContact()
{
	std::cout << "\033[1;32m";
	std::cout << "First Name : " << "\033[0m" << this->firstName << std::endl;
	std::cout << "\033[1;32m";
	std::cout << "Last Name : " << "\033[0m" << this->lastName << std::endl;
	std::cout << "\033[1;32m";
	std::cout << "Nickname : " << "\033[0m" << this->nickname << std::endl;
	std::cout << "\033[1;32m";
	std::cout << "Phone Number: " << "\033[0m" << this->phoneNumber << std::endl;
	std::cout << "\033[1;32m";
	std::cout << "Darkest secret : " << "\033[0m" << this->darkestSecret << std::endl;
}

std::string Contact::trunc(std::string str)
{
	std::string buf;

	buf = str.substr(0, 9);
	buf += ".";
	return (buf);
}

std::string	Contact::getInfo(std::string what)
{
	if (what == "first name")
	{
		if (this->firstName.length() > 10)
			return (this->trunc(this->firstName));
		else
			return (this->firstName);
	}
	else if (what == "last name")
	{
		if (this->lastName.length() > 10)
			return (this->trunc(this->lastName));
		else
			return (this->lastName);
	}
	else if (what == "nickname")
	{
		if (this->nickname.length() > 10)
			return (this->trunc(this->nickname));
		else
			return (this->nickname);
	}
	return ("");
}

void	Contact::init()
{
	std::string buff;

	buff = "";
	while (buff.length() == 0)
	{
		std::cout << "\033[1;32m";
		std::cout << "Please, give me your First Name : ";
		std::cout << "\033[0m";
		if (!std::getline(std::cin, buff))
			return ;
		if (buff.find('\t') != std::string::npos)
		{
            std::cout << "The entry must not contain tabs. Try again." << std::endl;
			buff = "";
        }
	}
	this->firstName = buff;

	buff = "";
	while (buff.length() == 0)
	{
		std::cout << "\033[1;32m";
		std::cout << "Now, your Last Name : ";
		std::cout << "\033[0m";
		if (!std::getline(std::cin, buff))
			return ;
		if (buff.find('\t') != std::string::npos)
		{
            std::cout << "The entry must not contain tabs. Try again." << std::endl;
			buff = "";
        }
	}
	this->lastName = buff;

	buff = "";
	while (buff.length() == 0)
	{
		std::cout << "\033[1;32m";
		std::cout << "And your little and cute Nickname ? ";
		std::cout << "\033[0m";
		if (!std::getline(std::cin, buff))
			return ;
		if (buff.find('\t') != std::string::npos)
		{
            std::cout << "The entry must not contain tabs. Try again." << std::endl;
			buff = "";
        }
	}
	this->nickname = buff;

	buff = "";
	while (buff.length() == 0)
	{
		std::cout << "\033[1;32m";
		std::cout << "Here, I need your phone Number: ";
		std::cout << "\033[0m";
		if (!std::getline(std::cin, buff))
			return ;
		if (buff.find('\t') != std::string::npos)
		{
            std::cout << "The entry must not contain tabs. Try again." << std::endl;
			buff = "";
        }
	}
	this->phoneNumber = buff;

	buff = "";
	while (buff.length() == 0)
	{
		std::cout << "\033[1;32m";
		std::cout << "And for finish, tell me more about your darkest secret: ";
		std::cout << "\033[0m";
		if (!std::getline(std::cin, buff))
			return ;
		if (buff.find('\t') != std::string::npos)
		{
            std::cout << "The entry must not contain tabs. Try again." << std::endl;
			buff = "";
        }
	}
	this->darkestSecret = buff;
}