/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:29:01 by root              #+#    #+#             */
/*   Updated: 2023/11/15 12:07:52 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


template<typename T>
void printArrayValue(T &iElement)
{
	std::cout << iElement << " ";
}

template <typename T, typename T2, typename T3>
void iter(T *adressOfArray, T2 lengthOfArray, T3 function)
{
    for (T2 i = 0; i < lengthOfArray; i++)
        function(adressOfArray[i]);
}
