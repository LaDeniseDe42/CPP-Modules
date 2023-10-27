/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:03:51 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/26 15:52:54 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string   name;
    bool                signOrNot;
    const int           requiredGradeToSign;
    const int           requiredGradeToExecute;
    
public:
    //Orthodox Canonical AForm
    AForm();//default constructor
    virtual ~AForm();//destructor
    AForm(const AForm&	newAForm); //cpy constructor
    AForm& operator=(AForm const & objectToCopy); //Copy assignment operator
    AForm(const std::string Name, const int RGE, const int RGS);
    
    //Functions
    const std::string   getName() const;
    int           getGradeToSign() const;
    int           getGradeToExecute() const;
    void                beSigned(Bureaucrat & theWorkingBureaucrat);
    bool                getSignOrNot() const;

    virtual void    execute(Bureaucrat const & executor) const = 0; // Méthode virtuelle pure
    

            //Exception
    class GradeTooLowException : public std::exception
    {
         public:
         virtual const char* what() const throw()
        {
            return ("\033[35mERROR :\033[0m need a better grade." );
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
    class FormNotSignedException : public std::exception
    {
        public:
        virtual const char* what() const throw()
        {
              return ("\033[35mERROR :\033[0m the form is not signed." );
         }
     };
};

std::ostream&	operator<<(std::ostream& os, const AForm& objet);


#endif