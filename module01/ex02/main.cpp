/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:28 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/19 09:38:53 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ COLOR DEFINES ~~~                           */
/*                                                                            */
/* ************************************************************************** */

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define END "\033[0m"

/* ************************************************************************** */
/*                                                                            */
/*                                ~~~ MAIN ~~~                                */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;


	std::cout << GREEN
			  << "[TEST] - DISPLAYING THE ADRESS OF THE STRING USING :"
			  << END << std::endl;

	std::cout << "\t- The string variable\t\t:\t"
			  << &str << std::endl;

	std::cout << "\t- The pointer to the string\t:\t"
			  << stringPTR << std::endl;

	std::cout << "\t- The reference to the string\t:\t"
			  << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << GREEN
			  << "[TEST] - DISPLAYING THE STRING USING :"
			  << END << std::endl;

	std::cout << "\t- The string variable\t\t:\t"
			  << str << std::endl;

	std::cout << "\t- The pointer to the string\t:\t"
			  << *stringPTR << std::endl;

	std::cout << "\t- The reference to the string\t:\t"
			  << stringREF << std::endl;

	return (0);
}