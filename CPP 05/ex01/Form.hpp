/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:03:51 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/24 16:51:30 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class Form : public std::exception
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

};


#endif