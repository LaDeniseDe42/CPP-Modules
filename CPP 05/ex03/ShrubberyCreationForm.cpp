/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:08:30 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/26 15:50:03 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//CONSTRUCTEURS

//default
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyForm", 137, 145), target("Unknown")
{
	std::cout << "\033[33mShrubberyCreationForm default constructor called \033[0m " << std::endl;
}

//cpy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm&	newShrubberyCreationForm) : AForm("ShrubberyForm", 137, 145), target(newShrubberyCreationForm.target)
{ 
	std::cout << "\033[33mShrubberyCreationForm Copy constructor called\033[0m " << std::endl;
	*this = newShrubberyCreationForm;
}

//Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & objectToCopy)
{
	std::cout << "\033[33mShrubberyCreationForm Copy assignment operator called\033[0m " << std::endl;
	if (this != &objectToCopy)
	{
        this->target = objectToCopy.target;
	}
	return (*this);
}

//cpy with targetName
ShrubberyCreationForm::ShrubberyCreationForm(const std::string targetName) : AForm("ShrubberyForm", 137, 145), target(targetName)
{
    std::cout << "\033[33mShrubberyCreationForm with targetName called\033[0m " << std::endl;
}

//destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Hey you i'm \033[36mShrubberyCreationForm\033[0m destructor" << std::endl;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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
        std::ofstream file;
        file.open((this->target + "_shrubbery").c_str());
        if (file.is_open())
        {
            file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n";
            file.close();
        }
        else
            std::cout << "Unfortunatly the file can't be opened" << std::endl;
    }     
}