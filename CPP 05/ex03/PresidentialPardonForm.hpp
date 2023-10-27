/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:13:13 by root              #+#    #+#             */
/*   Updated: 2023/10/27 09:14:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target;
    
public:
     //Orthodox Canonical Form
    PresidentialPardonForm();//default constructor
    ~PresidentialPardonForm();//destructor
    PresidentialPardonForm(const PresidentialPardonForm&	newPresidentialPardonForm); //cpy constructor
    PresidentialPardonForm& operator=(PresidentialPardonForm const & objectToCopy); //Copy assignment operator
    PresidentialPardonForm(const std::string targetName);

    void    execute(Bureaucrat const & executor) const;
};