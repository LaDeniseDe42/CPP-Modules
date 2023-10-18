/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:55:30 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/29 15:34:24 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replaceString.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Please retry with good arguments" << std::endl;
		return(1);
	}
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::string	forOutput = filename + ".replace";

	replaceString	repLace(s1, s2);
	if (repLace.replaceInFile(filename, forOutput))
        std::cout << "Operation is a SUCCESS" << std::endl;
	else
	{
        std::cerr << "This is a FAIL :( )" << std::endl;
        return 1;
    }
	return (0);
}