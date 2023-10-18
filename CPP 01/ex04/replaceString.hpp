/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceString.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:51:09 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/29 15:32:12 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACESTRING_HPP
# define REPLACESTRING_HPP

#include <iostream>
#include <fstream>
#include <string>

class replaceString
{
private:
	std::string	s1_;
	std::string s2_;

public:
	replaceString();
	replaceString(const std::string& s1, const std::string& s2);
	~replaceString();
	void	replaceThisString(std::string& line);
    bool replaceInFile(const std::string& inputFileName, const std::string& outputFileName);

};


#endif