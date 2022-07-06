/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:48:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/06 11:55:30 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

void    print_error(int errno)
{
    if (errno == N_ARG_ERR)
        std::cout << "Invalid number of argument !" << std::endl;
    std::cout << "Usage : ./replacer [filename] [str_to_replace] [new_str]" << std::endl;
}