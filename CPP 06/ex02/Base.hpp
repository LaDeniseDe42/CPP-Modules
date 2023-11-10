/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:48:03 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/10 09:38:52 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

//sans fonction virtuele, impossible d'utiliser le dynamic cast
//car le dynamic_cast ne fonctionne qu'avec le polymorphisme
class Base
{
    public:
        virtual ~Base();
};




