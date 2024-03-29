/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myReplace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:55:14 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/22 13:35:10 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

void	myReplace(std::string infileName, std::string old, std::string sub, std::string outfileName)
{
	std::ifstream	infile(infileName);
	std::string		text;

	if (infile)
	{
		text = getText(infile);
		if (text.length())
		{
			if (replaceLoop(text, old, sub, outfileName))
				std::cout << "Substitution done !" << std::endl;
			else
			{
				std::cout << "No occurence of \"" << old
						<< "\" in " << infileName << std::endl;
			}
		}
	}
	else
		printError(NO_INFILE);

	infile.close();

	return ;
}

std::string getText(std::ifstream &infile)
{
	std::string	line;
	std::string	text;

	try
	{
		while (std::getline(infile, line))
		{
			if (!infile.eof())
				line.append("\n");
			text += line;
		}
	}
	catch (std::out_of_range &e)
	{
		printError(EMPTY_FILE);
	}
	return (text);
}

int	 replaceLoop(std::string text, std::string old, std::string sub, std::string outfileName)
{
	std::ofstream	outfile(outfileName);
	bool			replaceState = false;
	std::size_t		foundPos = 0;
	std::size_t		checkPos = 0;

	while (foundPos != std::string::npos)
	{
		foundPos = text.find(old, checkPos);
		if (foundPos == std::string::npos)
			break ;

		text.erase(foundPos, old.length());
		text.insert(foundPos, sub);

		checkPos = foundPos + sub.length();
		replaceState = true;
	}

	outfile << text;
	outfile.close();

	return (replaceState);
}
