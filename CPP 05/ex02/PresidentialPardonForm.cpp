/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:13:31 by root              #+#    #+#             */
/*   Updated: 2023/10/27 09:34:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//CONSTRUCTEURS

//default
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialForm", 5, 25), target("LambdaCriminal")
{
	std::cout << "\033[33mPresidentialPardonForm default constructor called \033[0m " << std::endl;
}

//cpy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm&	newPresidentialPardonForm) : AForm("PresidentialForm", 5, 25), target(newPresidentialPardonForm.target)
{ 
	std::cout << "\033[33mPresidentialPardonForm Copy constructor called\033[0m " << std::endl;
	*this = newPresidentialPardonForm;
}

//Copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & objectToCopy)
{
	std::cout << "\033[33mPresidentialPardonForm Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
        this->target = objectToCopy.target;
	}
	return (*this);
}

//cpy with targetName
PresidentialPardonForm::PresidentialPardonForm(const std::string targetName) : AForm("PresidentialForm", 5, 25), target(targetName)
{
    std::cout << "\033[33mPresidentialPardonForm with targetName called\033[0m " << std::endl;
}

//destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Hey you i'm \033[36mPresidentialPardonForm\033[0m destructor" << std::endl;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
    {
        throw AForm::GradeTooLowException();
    }
     else if (this->getSignOrNot() == false)
    {
        std::cout << "there is no signature on this sheet" << std::endl;   
         throw AForm::FormNotSignedException();
    }
    else
    {
        std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
    }     
}