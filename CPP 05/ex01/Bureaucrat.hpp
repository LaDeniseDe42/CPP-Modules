/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:07:29 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/24 14:16:39 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

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
    
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& objet);

#endif