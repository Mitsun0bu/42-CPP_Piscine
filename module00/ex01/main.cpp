/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:50:04 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/30 18:57:28 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Contact.hpp"
# include "PhoneBook.hpp"

void	print_menu(void);

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input = "";
	int			i_input = 0;

	/*
		Ask the user for an input :
		ADD, SEARCH and EXIT are accepted
		Other input is discarded
	*/
	while(input != "EXIT")
	{
		print_menu();
		std::cin >> input;
		if (input == "ADD")
		{
			phonebook.add_contact(&i_input);
			i_input ++;
		}
		else if (input == "SEARCH")
			phonebook.search_contact();
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