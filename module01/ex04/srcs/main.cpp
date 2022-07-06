/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:42:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/06 19:13:51 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

int main(int ac, char **av)
{
    (void)av;
    
    if (ac == 4)
    {
        std::string 	infile_name(av[1]);
        std::string 	old(av[2]);
        std::string     sub(av[3]);
        std::string 	outfile_name = infile_name + ".replace";

        if (infile_name.empty() || old.empty() || sub.empty())
            print_error(EMPTY_ARG_ERR);

        replace(infile_name, old, sub, outfile_name);

        return 0;
    }
    print_error(N_ARG_ERR);
    return (0);
}
