/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:40:15 by root              #+#    #+#             */
/*   Updated: 2023/11/10 14:42:44 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern&	newIntern); //cpy constructor
        Intern& operator=(Intern const & objectToCopy); //Copy assignment operator 

        AForm *makeForm(std::string const & formName, std::string const & targetName);
        void   makeMeACofee(Bureaucrat who);
        class FormNotFoundException : public std::exception
        {
            public:
            virtual const char* what() const throw()
            {
                return ("\033[35mERROR :\033[0m Form not found" );
            }
        };
    
};

