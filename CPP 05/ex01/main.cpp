/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:43 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/10 16:37:45 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat emperor("Palpatine", 1);
        std::cout << emperor;
        Form kill_the_jedi("66_Order", 1, 1);
        std::cout << kill_the_jedi;
        emperor.signForm(kill_the_jedi);

        std::cout << std::endl;
        
        Bureaucrat blackHole("Jeannai Plupourlong", 129);
        std::cout << blackHole;
        Form phenix("INeedMoreTime", 10, 129);
        std::cout << phenix;
        blackHole.signForm(phenix);
        blackHole.decreaseGrade();
        std::cout << blackHole;
        blackHole.signForm(phenix);
        
    }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(Form::GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(Form::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}