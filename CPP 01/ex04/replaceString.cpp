/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceString.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:51:30 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/20 13:32:21 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replaceString.hpp"

replaceString::replaceString()
{
	
}

replaceString::replaceString(const std::string& s1, const std::string& s2) : s1_(s1), s2_(s2)
{
}

replaceString::~replaceString()
{
}

void	replaceString::replaceThisString(std::string& line)
{
	size_t	posStart = 0;
	size_t	foundCharToReplace = line.find(s1_, posStart);

	while (foundCharToReplace != std::string::npos)
	{
        line = line.substr(0, foundCharToReplace) + s2_ + line.substr(foundCharToReplace + s1_.length());
        posStart = foundCharToReplace + s2_.length();
        foundCharToReplace = line.find(s1_, posStart);
    }
}

bool replaceString::replaceInFile(const std::string& inputFileName, const std::string& outputFileName)
{
	std::ifstream inputFile(inputFileName);
    if (!inputFile)
	{
        std::cerr << "Erreur : Can't open inputFile" << std::endl;
        return false;
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile)
	{
        std::cerr << "Erreur : Cant't open outputFile" << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(inputFile, line))
	{
        replaceThisString(line);
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return (true);
}