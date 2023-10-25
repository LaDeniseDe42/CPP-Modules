/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:04:05 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/25 15:47:44 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


//CONSTRUCTEURS

//default
Form::Form() : name("Unknown"), requiredGradeToSign(1), requiredGradeToExecute(10)
{
	std::cout << "\033[33mForm default constructor called \033[0m " << std::endl;
}

//cpy constructor
Form::Form(const Form&	newForm) : name(newForm.name), requiredGradeToSign(1), requiredGradeToExecute(10)
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

Form::Form(const std::string Name, const int RGE, const int RGS) : name(Name) , requiredGradeToSign(RGS), requiredGradeToExecute(RGE)
{
    std::cout << "\033[33mForm with name and levels called\033[0m " << std::endl;
   		if (requiredGradeToExecute < 1 || requiredGradeToSign < 1)
		{
			throw GradeTooHighException();
		}
		else if (requiredGradeToExecute > 150 || requiredGradeToSign > 150)
		{
			throw GradeTooLowException();
		}	
	
}

				//FUNCTIONS

    const std::string	Form::getName() const
	{
		return(this->name);
	}
	
    bool	Form::getSignOrNot() const
	{
		if (signOrNot > 0)
			return(true);
		else
			return(false);
	}
	
    int	Form::getGradeToSign() const
	{
		return (this->requiredGradeToSign);
	}

    int	Form::getGradeToExecute() const
	{
		return (this->requiredGradeToExecute);
	}


	void	Form::beSigned(Bureaucrat theWorkingBureaucrat)
	{

		if (theWorkingBureaucrat.getGrade() > getGradeToSign())
		{
			throw GradeTooLowException();
		}
		else
		{
			signOrNot = 666;
		}

	}


std::ostream&	operator<<(std::ostream& os, const Form& objet)
{
	os << objet.getName() << " formulate can be signed with this grade : " << objet.getGradeToSign();
	os << " and can be execute with this grade : " << objet.getGradeToExecute() << std::endl;
	return (os);
}

//destructor
Form::~Form()
{
	std::cout << "Hey you i'm \033[36mForm\033[0m destructor" << std::endl;
}