/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:42:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/19 09:45:07 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

int main(int ac, char **av)
{
	(void)av;

	if (ac == 4)
	{
		std::string	infileName(av[1]);
		std::string	old(av[2]);
		std::string	sub(av[3]);
		std::string	outfileName = infileName + ".replace";

		if (infileName.empty() || old.empty() || sub.empty())
			printError(EMPTY_ARG_ERR);

		myReplace(infileName, old, sub, outfileName);

		return 0;
	}

	printError(N_ARG_ERR);

	return (0);
}
