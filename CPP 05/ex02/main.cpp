/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:43 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/26 15:57:54 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

        std::cout << std::endl;
        
        // Bureaucrat blackHole("Jeannai Plupourlong", 129);
        // std::cout << blackHole;
        // AForm phenix("INeedMoreTime", 10, 129);
        // std::cout << phenix;
        // blackHole.signForm(phenix);
        // blackHole.decreaseGrade();
        // std::cout << blackHole;
        // blackHole.signForm(phenix);
        delete kill_the_jedi;
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