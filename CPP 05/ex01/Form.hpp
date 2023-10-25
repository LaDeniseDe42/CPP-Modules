/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:03:51 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/25 16:10:21 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string   name;
    bool                signOrNot;
    const int           requiredGradeToSign;
    const int           requiredGradeToExecute;
    
public:
    //Orthodox Canonical Form
    Form();//default constructor
    ~Form();//destructor
    Form(const Form&	newForm); //cpy constructor
    Form& operator=(Form const & objectToCopy); //Copy assignment operator
    Form(const std::string Name, const int RGE, const int RGS);
    
    //Functions
    const std::string   getName() const;
    int           getGradeToSign() const;
    int           getGradeToExecute() const;
    void                beSigned(Bureaucrat theWorkingBureaucrat);
    bool                getSignOrNot() const;
    

            //Exception
    class GradeTooLowException : public std::exception
    {
         public:
         virtual const char* what() const throw()
        {
            return ("\033[35mERROR :\033[0m need a better grade for sign this." );
        }
    };
        
    class GradeTooHighException : public std::exception
    {
        public:
        virtual const char* what() const throw()
        {
              return ("\033[35mERROR :\033[0m this grade doesn't exist." );
         }
     };
};

std::ostream&	operator<<(std::ostream& os, const Form& objet);


#endif