/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:26:36 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/18 09:50:32 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i = 1;
	int	j = 0;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
	else
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				argv[i][j] = toupper(argv[i][j]);
				std::cout << argv[i][j];
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
