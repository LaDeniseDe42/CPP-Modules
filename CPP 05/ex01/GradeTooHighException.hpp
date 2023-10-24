/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:27:15 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/24 13:41:54 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOHIGHTEXCEPTION_HPP
#define GRADETOOHIGHTEXCEPTION_HPP

#include <stdexcept>

class GradeTooHighException : public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return ("\033[35mERROR :\033[0m The grade is too HIGHT" );
    }
   
};

#endif