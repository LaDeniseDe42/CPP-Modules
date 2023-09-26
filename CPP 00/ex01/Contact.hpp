/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:32:25 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/06 14:22:38 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <csignal>

class Contact
{
	private:

	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	std::string index;

	public:
	Contact();
	~Contact();
	void    init(void);
	std::string	getInfo(std::string what);
	std::string	trunc(std::string str);
	void	seeContact(void);
};

#endif