/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:43 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/27 11:32:34 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        // Bureaucrat emperor("Palpatine", 1);
        // std::cout << emperor;
        // AForm* kill_the_jedi = new ShrubberyCreationForm("Endor");
        // std::cout << *kill_the_jedi;
        // emperor.signForm(*kill_the_jedi);
        // emperor.executeForm(*kill_the_jedi);

        // std::cout << std::endl;
        
        // Bureaucrat Sadic("Docteur UneChanceSurDeux", 1);
        // std::cout << Sadic;
        // AForm* pileOuFace = new RobotomyRequestForm("MaFoi TaPasDeChance");
        // std::cout << *pileOuFace;
        // Sadic.signForm(*pileOuFace);
        // Sadic.executeForm(*pileOuFace);

        // std::cout << std::endl;

        // Bureaucrat president("Cornelius Fudge", 1);
        // std::cout << president;
        // AForm* pardon = new PresidentialPardonForm("Lucius Malefoy");
        // std::cout << *pardon;
        // president.signForm(*pardon);
        // president.executeForm(*pardon);
        
        // std::cout << std::endl;
        // delete kill_the_jedi;
        // delete pileOuFace;
        // delete pardon;
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "12 rue de la Commanderie");
    std::cout << *rrf;
    Bureaucrat b("Georges", 15);
    b.signForm(*rrf);
    b.executeForm(*rrf);
    someRandomIntern.makeMeACofee(b);
    b.throwCoffee();
    delete rrf;
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    // catch(Bureaucrat::GradeTooHighException & e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    // catch(Bureaucrat::GradeTooLowException & e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    // catch(AForm::GradeTooLowException & e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    // catch(AForm::GradeTooHighException & e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    // catch(AForm::FormNotSignedException & e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    // catch(Intern::FormNotFoundException & e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    return (0);
}