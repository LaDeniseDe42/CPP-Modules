/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:07:16 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/27 11:31:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"


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


void	Bureaucrat::signForm(AForm & formToCheck)
{
	try
	{
		formToCheck.beSigned(*this);
		if(formToCheck.getSignOrNot() == true)
		{
			std::cout << "\033[42m" << getName() << " signed " << formToCheck.getName() << "\033[00m" << std::endl;
		}	
	}
	catch(const std::exception& e)
	{
		std::cout << "\033[41m" << getName() << " couldn't signed " << formToCheck.getName();
		std::cout << " because is grade is too low.." << "\033[00m" << std::endl;
		std::cerr << e.what() << '\n';
	}
	
}


void    Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << "\033[42m" << this->getName() << " executed " << form.getName() << "\033[00m"<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "\033[41m" << this->getName() << " can't execute " << form.getName() << "\033[00m"<< std::endl;
		std::cerr << e.what() << std::endl;
	}
	
}

void    Bureaucrat::throwCoffee()
{
	std::cout << this->getName() << " throw a coffee on the floor beacause intern forgot sugar" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& objet)
{
	os << "\033[34m" <<objet.getName() << ", bureaucrat grade " << objet.getGrade() << "\033[00m" << std::endl;
	return (os);
}