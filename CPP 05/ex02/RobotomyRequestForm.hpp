/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:59:31 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/26 16:02:31 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string target;
    
public:
     //Orthodox Canonical Form
    RobotomyRequestForm();//default constructor
    ~RobotomyRequestForm();//destructor
    RobotomyRequestForm(const RobotomyRequestForm&	newRobotomyRequestForm); //cpy constructor
    RobotomyRequestForm& operator=(RobotomyRequestForm const & objectToCopy); //Copy assignment operator
    RobotomyRequestForm(const std::string targetName);

    void    execute(Bureaucrat const & executor) const;
};