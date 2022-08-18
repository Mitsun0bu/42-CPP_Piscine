/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myReplace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:55:14 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/18 16:23:30 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

void    myReplace(std::string infileName, std::string old, std::string sub, std::string outfileName)
{
    std::ifstream   infile(infileName);
    std::string     text;

    if (infile)
    {
        text = getText(infile);
        if (replaceLoop(text, old, sub, outfileName))
            std::cout << "Substitution done !" << std::endl;
        else
        {
            std::cout << "No occurence of \"" << old
                      << "\" in " << infileName << std::endl;
        }
    }
    else
        printError(NO_INFILE);

    infile.close();

    return ;
}

std::string getText(std::ifstream &infile)
{
    std::string word;
    std::string text;

    while (infile >> word)
    {
        word = word + ' ';
        text += word;
    }
    text.erase(text.size()-1,1);

    return (text);
}

int     replaceLoop(std::string text, std::string old, std::string sub, std::string outfileName)
{
    std::ofstream   outfile(outfileName);
    bool            replaceState = false;
    std::size_t     foundPos = 0;
    std::size_t     checkPos = 0;

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
