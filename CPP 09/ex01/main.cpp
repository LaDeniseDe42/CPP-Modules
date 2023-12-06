/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:22:53 by qdenizar          #+#    #+#             */
/*   Updated: 2023/12/06 10:51:46 by root             ###   ########.fr       */
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
        std::cout << "\033[0;33mUsage: ./RPN \"Inverse polish notation\"\033[0m" << std::endl;
        return (1);
    }
    std::cout << "\033[0;32m/*-+/*-+/*-+/*-+/*-+/*-+/*-+/*-+/*-+/*-+*-+/" << std::endl;
     std::cout << "/ \033[0;35m         WELCOME DEAR USER              \033[0;32m/" << std::endl; 
    std::cout << "/ \033[0;35mThis RPN manage number between 0 and 9 \033[0;32m/" << std::endl; 
    std::cout << "/*-+/*-+/*-+/*-+/*-+/*-+/*-+/*-+/*-+/*-+/\033[0m" << std::endl;
    RPN rpn;
    i = rpn.parse(argv[1]);
    if (i != 0)
    {
        rpn.error(i);
        return (1);
    }
    else
        i = rpn.rpn(argv[1]);
    return (i);
}
