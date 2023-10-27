/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:08:14 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/26 14:00:46 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;
    
public:
     //Orthodox Canonical Form
    ShrubberyCreationForm();//default constructor
    ~ShrubberyCreationForm();//destructor
    ShrubberyCreationForm(const ShrubberyCreationForm&	newShrubberyCreationForm); //cpy constructor
    ShrubberyCreationForm& operator=(ShrubberyCreationForm const & objectToCopy); //Copy assignment operator
    ShrubberyCreationForm(const std::string targetName);

    void    execute(Bureaucrat const & executor) const;
};


