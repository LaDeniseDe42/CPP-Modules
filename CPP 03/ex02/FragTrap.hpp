/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:28:41 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/04 15:10:09 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
    public:
    //Orthodox Canonical Form
    FragTrap(); //default constructor
    FragTrap(const FragTrap&	newFragTrap); //cpy constructor
    FragTrap& operator=(FragTrap const & objectToCopy); //Copy assignment operator
    ~FragTrap(); //destructor

    FragTrap(std::string Name);
    
    void highFivesGuys(void);
    void beRepaired(unsigned int amount);
};

#endif