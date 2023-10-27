/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:40:29 by root              #+#    #+#             */
/*   Updated: 2023/10/27 11:22:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <stdexcept>


//default constructor
Intern::Intern()
{
}

//cpy constructor
Intern::Intern(const Intern&	newIntern)
{ 
    *this = newIntern;
}

//Copy assignment operator
Intern& Intern::operator=(Intern const & objectToCopy)
{
    if (this != &objectToCopy)
    {
    }
    return (*this);
}

        //FUNCTIONS

static AForm *createShrubberyForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *createPresidentialForm(std::string target)
{
	return new PresidentialPardonForm(target);
}
static AForm *createRobotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(std::string const & formName, std::string const & targetName)
{
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*formTab[3])(std::string) = {createShrubberyForm, createRobotomyForm, createPresidentialForm};
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "\033[42m" << "Intern creates " << formName << "\033[00m" << std::endl;
            return (formTab[i](targetName));
        }
    }
    std::cout << "\033[41m" << "Intern can't create " << formName << "\033[00m" << std::endl;
	throw FormNotFoundException();
}

void   Intern::makeMeACofee(Bureaucrat who)
{
    std::cout << "Intern makes a cofee for " << who.getName() << std::endl;
}

//destructor
Intern::~Intern()
{
}
