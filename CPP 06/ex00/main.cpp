/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:31:35 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/07 14:29:07 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "How to use CONVERTOR =>  " << argv[0] << " <input>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}