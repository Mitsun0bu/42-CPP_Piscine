/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:11:55 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/06 19:13:55 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

void    print_error(int error_type)
{
    if (error_type == N_ARG_ERR)
        std::cout << "Invalid number of argument !" << std::endl;
    else if (error_type == NO_INFILE)
        std::cout << "Cannot read the infile !" << std::endl;
    else if (error_type == EMPTY_ARG_ERR)
        std::cout << "One of your argument is empty !" << std::endl;
    std::cout << "Usage : ./replacer [filename] [str_to_replace] [new_str]"
              << std::endl;
}
