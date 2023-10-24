/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:04:05 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/24 16:54:35 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


//CONSTRUCTEURS

//default
Form::Form() : name("Unknown"), requiredGradeToExecute(10), requiredGradeToSign(1)
{
	std::cout << "\033[33mForm default constructor called \033[0m " << std::endl;
}

//cpy constructor
Form::Form(const Form&	newForm) : name(newForm.name), requiredGradeToExecute(10), requiredGradeToSign(1)
{ 
	std::cout << "\033[33mForm Copy constructor called\033[0m " << std::endl;
	*this = newForm;
}

//Copy assignment operator
Form& Form::operator=(Form const & objectToCopy)
{
	std::cout << "\033[33mForm Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
        this->signOrNot = objectToCopy.signOrNot;
	}
	return (*this);
}

Form::Form(const std::string Name, const int RGE, const int RGS) : name(Name), requiredGradeToExecute(RGE), requiredGradeToSign(RGS)
{
    std::cout << "\033[33mForm with name and levels called\033[0m " << std::endl;
    if (requiredGradeToExecute < 1 || requiredGradeToSign < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade_ > 150)
	{
		throw GradeTooLowException();
	}
}

//destructor
Form::~Form()
{
	std::cout << "Hey you i'm \033[36mForm\033[0m destructor" << std::endl;
}