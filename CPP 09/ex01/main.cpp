/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:22:53 by qdenizar          #+#    #+#             */
/*   Updated: 2023/12/05 09:39:52 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include "RPN.hpp"

int    main(int argc, char **argv)
{
    int i =0;
    if (argc != 2)
    {
        std::cout << "Usage: ./RPN \"Inverse polish notation\"" << std::endl;
        return (1);
    }
    std::cout << "argv[1] = " << argv[1] << std::endl; 
    RPN rpn;
    rpn.setNb();
    i = rpn.parse(argv[1], 0);
    if (i != 0)
    {
        rpn.error(i);
        return (1);
    }
    return (0);
}