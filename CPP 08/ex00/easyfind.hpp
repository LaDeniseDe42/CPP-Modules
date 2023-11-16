/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:42:20 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/16 15:24:02 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


template<typename T>
int easyfind(T &container, int value)
{
    typename T::iterator searchTheValue;
    searchTheValue = std::find(container.begin(), container.end(), value);
    if (searchTheValue != container.end())
        std::cout << "Value " << value << " found" << std::endl;
    else
    {
        std::cout << "Value " << value << " not found" << std::endl;
        return (666);
    }
    return (0);
}