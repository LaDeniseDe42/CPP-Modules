/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:23:05 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/24 14:05:01 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOLOWEXCEPTION_HPP
#define GRADETOOLOWEXCEPTION_HPP

#include <stdexcept>

class GradeTooLowException : public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return ("\033[35mERROR :\033[0m The grade is too LOW" );
    }
   
};

#endif