/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:04:05 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/26 15:57:12 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


//CONSTRUCTEURS

//default
AForm::AForm() : name("Unknown"), signOrNot(false), requiredGradeToSign(1), requiredGradeToExecute(10)
{
	std::cout << "\033[33mAForm default constructor called \033[0m " << std::endl;
}

//cpy constructor
AForm::AForm(const AForm&	newAForm) : name(newAForm.name), signOrNot(false), requiredGradeToSign(1), requiredGradeToExecute(10)
{ 
	std::cout << "\033[33mAForm Copy constructor called\033[0m " << std::endl;
	*this = newAForm;
}

//Copy assignment operator
AForm& AForm::operator=(AForm const & objectToCopy)
{
	std::cout << "\033[33mAForm Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
        this->signOrNot = objectToCopy.signOrNot;
	}
	return (*this);
}

AForm::AForm(const std::string Name, const int RGE, const int RGS) : name(Name) , requiredGradeToSign(RGS), requiredGradeToExecute(RGE)
{
    std::cout << "\033[33mAForm with name and levels called\033[0m " << std::endl;
   		if (requiredGradeToExecute < 1 || requiredGradeToSign < 1)
		{
			throw GradeTooHighException();
		}
		if (requiredGradeToExecute > 150 || requiredGradeToSign > 150)
		{
			throw GradeTooLowException();
		}	
} 

				//FUNCTIONS

    const std::string	AForm::getName() const
	{
		return(this->name);
	}
	
    bool	AForm::getSignOrNot() const
	{
		if (signOrNot == true)
			return(true);
		else
			return(false);
	}
	
    int	AForm::getGradeToSign() const
	{
		return (this->requiredGradeToSign);
	}

    int	AForm::getGradeToExecute() const
	{
		return (this->requiredGradeToExecute);
	}


	void	AForm::beSigned(Bureaucrat  & theWorkingBureaucrat)
	{
		if (theWorkingBureaucrat.getGrade() > getGradeToSign())
		{
			std::cout << "\033[34m" << "This form dont have any signature" << "\033[00m" <<std::endl;
			throw GradeTooLowException();
		}
		else
		{
			signOrNot = true;
		}

	}


std::ostream&	operator<<(std::ostream& os, const AForm& objet)
{
	os << "\033[34m" << objet.getName() << " can be signed with level : " << objet.getGradeToSign();
	os << " and can be execute with level : " << objet.getGradeToExecute() << "\033[00m" << std::endl;
	return (os);
}

//destructor
AForm::~AForm()
{
	std::cout << "Hey you i'm \033[36mAForm\033[0m destructor" << std::endl;
}