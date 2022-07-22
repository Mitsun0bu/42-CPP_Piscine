/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:43:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/22 20:02:29 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error : Invalid number of arguments" << std::endl;
		std::cerr << "Usage : ./scalar_conversion [arg_1]" << std::endl;
		return (0);
	}

	std::string	to_convert(av[1]);

	std::cout << std::endl << GREEN << "[TEST - VARIABLE TO CONVERT]" << END << std::endl;
	std::cout << to_convert << std::endl;

	/*
		1 - Detect the type of the literal passed as parameter
		2 - Convert it from string to its actual type
		3 - Convert it explicitly to the three other data types
		4 - Lastly, display the results as shown in the subject.
	*/

	return (0);
}