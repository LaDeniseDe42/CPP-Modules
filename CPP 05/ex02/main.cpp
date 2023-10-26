/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:43 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/26 16:36:36 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try
    {
        Bureaucrat emperor("Palpatine", 1);
        std::cout << emperor;
        AForm* kill_the_jedi = new ShrubberyCreationForm("42_Mulhouse");
        std::cout << *kill_the_jedi;
        emperor.signForm(*kill_the_jedi);
        emperor.executeForm(*kill_the_jedi);
        
        Bureaucrat Sadic("Docteur UneChanceSurDeux", 1);
        std::cout << Sadic;
        AForm* pileOuFace = new RobotomyRequestForm("MaFoi TaPasDeChance");
        std::cout << *pileOuFace;
        Sadic.signForm(*pileOuFace);
        Sadic.executeForm(*pileOuFace);

        std::cout << std::endl;
        
        
        delete kill_the_jedi;
        delete pileOuFace;
    }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(AForm::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}