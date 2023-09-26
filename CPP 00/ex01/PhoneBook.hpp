/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:53:43 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/07 09:41:30 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cstring>

#include "Contact.hpp"
#include <ncurses.h>

class PhoneBook
{
	private:

	Contact	users[8];
	std::string	buffer;

	public:
	
	PhoneBook( void );
	~PhoneBook( void );
	static void	helloPhone(void);
	void	addContact(void);
	void	searchContact(void);
	void	displayMyContact(int	index);
};

#endif