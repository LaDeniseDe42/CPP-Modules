/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:59:53 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/26 16:06:33 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include   "RobotomyRequestForm.hpp"

//CONSTRUCTEURS

//default
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyForm", 45, 72), target("OnePoorPerson")
{
	std::cout << "\033[33mRobotomyRequestForm default constructor called \033[0m " << std::endl;
}

//cpy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm&	newRobotomyRequestForm) : AForm("RobotomyForm", 45, 72), target(newRobotomyRequestForm.target)
{ 
	std::cout << "\033[33mRobotomyRequestForm Copy constructor called\033[0m " << std::endl;
	*this = newRobotomyRequestForm;
}

//Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & objectToCopy)
{
	std::cout << "\033[33mRobotomyRequestForm Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
        this->target = objectToCopy.target;
	}
	return (*this);
}

//cpy with targetName
RobotomyRequestForm::RobotomyRequestForm(const std::string targetName) : AForm("RobotomyForm", 45, 72), target(targetName)
{
    std::cout << "\033[33mRobotomyRequestForm with targetName called\033[0m " << std::endl;
}

//destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Hey you i'm \033[36mRobotomyRequestForm\033[0m destructor" << std::endl;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
        
    }     
}