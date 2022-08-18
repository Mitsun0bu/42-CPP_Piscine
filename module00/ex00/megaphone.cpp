/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:44:31 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/18 11:12:05 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	if (ac >= 2)
	{
		for (int i = 1; i < ac; i ++)
		{
			std::string	str(av[i]);
			for (int j = 0; j < (int)str.size(); j++)
				str[j] = std::toupper(str[j]);
			std::cout << str;
		}
		std::cout << std::endl;
	}

	return (0);
}