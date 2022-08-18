/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printError.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:55:27 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/18 18:38:50 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

void    printError(int errorType)
{
    if (errorType == N_ARG_ERR)
        std::cout << "Invalid number of argument !" << std::endl;
    else if (errorType == NO_INFILE)
        std::cout << "Cannot read the infile !" << std::endl;
    else if (errorType == EMPTY_ARG_ERR)
        std::cout << "One of your argument is empty !" << std::endl;
    else if (errorType == EMPTY_FILE)
        std::cerr << "File passed in argument is empty !" << std::endl;

    std::cout << "Usage : ./replacer [filename] [str_to_replace] [new_str]"
              << std::endl;
}
