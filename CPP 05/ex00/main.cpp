/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:43 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/24 14:43:33 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

int main()
{
    try
    {
        Bureaucrat test("Jean-Bon", 1);
        std::cout << test;
        test.decreaseGrade();
        test.decreaseGrade();
        test.promoteGrade();
        test.promoteGrade();
        //test.promoteGrade();
        std::cout << test << std::endl;
        
        Bureaucrat test2("Jean-Pas-Bon", 130);
        std::cout << test2;
        test2.decreaseGrade();
        test2.decreaseGrade();
        test2.decreaseGrade();
        test2.decreaseGrade();
        test2.decreaseGrade();
        std::cout << test2 << std::endl;
        
        
        Bureaucrat test3("Jean_Pas_Bon_Non_Plus", 149);
        std::cout << test3;
        test3.promoteGrade();
        test3.decreaseGrade();
        test3.decreaseGrade();
        //test3.decreaseGrade();
        std::cout << test3 << std::endl;
    }
    catch(GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    catch(GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}