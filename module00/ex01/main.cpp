/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:50:04 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/08 15:28:57 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

int	main(void)
{
	PhoneBook		phonebook;
	std::string		input = "";
	int				i_input = 0;

	while(input != "EXIT")
	{
		print_menu();

		std::cin >> input;

		if (std::cin.eof() == TRUE)
			return (0);

		if (input == "ADD")
		{
			if (phonebook.addContact(&i_input) == FAIL)
				return (0);
			i_input ++;
		}
		else if (input == "SEARCH")
		{
			if (phonebook.searchContact() == FAIL)
				return (0);
		}
		else
			continue ;
	}
	return (0);
}

void	print_menu(void)
{
	std::cout << "~~~ Welcome to your PhoneBook ~~~" << std::endl;
	std::cout << std::endl;
	std::cout << "The following commands are availble to you :" << std::endl;
	std::cout << "\t- ADD (save a new contact)" << std::endl;
	std::cout << "\t- SEARCH (display a specific contact)" << std::endl;
	std::cout << "\t- EXIT (quit the PhoneBook)" << std::endl;
	std::cout << std::endl;
	std::cout << "Please type the command you want to execute : ";
}
