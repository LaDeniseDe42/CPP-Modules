/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:07:29 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/25 15:31:46 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
    const   std::string name;
    int     grade;
    
    public:
        //Orthodox Canonical Form
        Bureaucrat();//default constructor
        ~Bureaucrat();//destructor
        Bureaucrat(const Bureaucrat&	newBureaucrat); //cpy constructor
        Bureaucrat& operator=(Bureaucrat const & objectToCopy); //Copy assignment operator
        Bureaucrat(std::string const & name_); //constructor with name
        Bureaucrat(std::string const & name_, int grade_);
        

        //Functions
        const std::string getName() const;
        int getGrade() const;
        void    promoteGrade();
        void    decreaseGrade();
        void    signForm(Form formToCheck);
        
        //Exception
        class GradeTooLowException : public std::exception
        {
            public:
            virtual const char* what() const throw()
            {
                return ("\033[35mERROR :\033[0m The grade is too LOW" );
            }
        };
        
        class GradeTooHighException : public std::exception
        {
            public:
            virtual const char* what() const throw()
            {
                return ("\033[35mERROR :\033[0m The grade is too HIGHT" );
            }
        };
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& objet);


