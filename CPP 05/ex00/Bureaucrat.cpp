/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:07:16 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/24 14:30:15 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

//CONSTRUCTEURS

//default
Bureaucrat::Bureaucrat() : name("Unknown"), grade(150)
{
	std::cout << "\033[33mBureaucrat default constructor called \033[0m " << std::endl;
}

//constructor with string
Bureaucrat::Bureaucrat(std::string const & name_) : name(name_), grade(150)
{
    std::cout << "\033[33mBureaucrat constructor with name called\033[0m " << std::endl;
}

Bureaucrat::Bureaucrat(std::string const & name_, int grade_) : name(name_), grade(grade_)
{
    std::cout << "\033[33mBureaucrat constructor with name and grade called\033[0m " << std::endl;
	if (grade_ < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade_ > 150)
	{
		throw GradeTooLowException();
	}
}

//cpy constructor
Bureaucrat::Bureaucrat(const Bureaucrat&	newBureaucrat) : name(newBureaucrat.name)
{ 
	std::cout << "\033[33mBureaucrat Copy constructor called\033[0m " << std::endl;
	*this = newBureaucrat;
}

//Copy assignment operator
Bureaucrat& Bureaucrat::operator=(Bureaucrat const & objectToCopy)
{
	std::cout << "\033[33mBureaucrat Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
        this->grade = objectToCopy.grade;
	}
	return (*this);
}

//destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Hey you i'm \033[36mBureaucrat\033[0m destructor" << std::endl;
}


//Function 

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return(this->grade);
}

void    Bureaucrat::promoteGrade()
{
	if (this->grade == 1)
	{
		throw GradeTooHighException();
	}
	else
		this->grade--;
}

void    Bureaucrat::decreaseGrade()
{
	if (this->grade == 150)
	{
		throw GradeTooLowException();
	}
	else
		this->grade++;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& objet)
{
	os << objet.getName() << ", bureaucrat grade " << objet.getGrade() << "." << std::endl;
	return (os);
}