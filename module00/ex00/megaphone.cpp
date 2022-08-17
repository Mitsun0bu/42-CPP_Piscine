/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:44:31 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/17 14:45:24 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	if (ac >= 2)
	{
		for (i = 1; i < ac; i ++)
		{
			std::string	str(av[i]);
			std::transform(str.begin(), str.end(),str.begin(), ::toupper);
			std::cout << str << " " ;
		}
		std::cout << std::endl;
	}

	return (0);
}