/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:43 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/10 14:40:58 by qdenizar         ###   ########.fr       */
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
        Bureaucrat emperor("Palpatine", 1);
        std::cout << emperor;
        AForm* kill_the_jedi = new ShrubberyCreationForm("Endor");
        std::cout << *kill_the_jedi;
        emperor.signForm(*kill_the_jedi);
        emperor.executeForm(*kill_the_jedi);
        delete kill_the_jedi;

        std::cout << std::endl;
        
        Bureaucrat Sadic("Docteur UneChanceSurDeux", 1);
        std::cout << Sadic;
        AForm* pileOuFace = new RobotomyRequestForm("MaFoi TaPasDeChance");
        std::cout << *pileOuFace;
        Sadic.signForm(*pileOuFace);
        Sadic.executeForm(*pileOuFace);
        delete pileOuFace;

        std::cout << std::endl;

        Bureaucrat president("Cornelius Fudge", 1);
        std::cout << president;
        AForm* pardon = new PresidentialPardonForm("Lucius Malefoy");
        std::cout << *pardon;
        president.signForm(*pardon);
        president.executeForm(*pardon);
        delete pardon;
        
        std::cout << std::endl;
        
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation", "foret");
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
    return (0);
}