/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:18:27 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/30 18:56:50 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <sstream>
# include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_n_contact = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add_contact(int *i)
{
	if (*i >= 8)
		*i = 0;
	this->contact[*i].set_contact_info(*i);
	if (this->_n_contact < 8)
		this->_n_contact++;
}

void	PhoneBook::search_contact(void)
{
	std::string	buff = "";
	int			i_contact = -1;

	/* Check if the phonebook has at least one contact */
	if (this->_n_contact == 0)
	{
		std::cout << std::endl;
		std::cout << "You don't have any contact in memory !" << std::endl;
		std::cout << std::endl;
		return ;
	}

	/* Display the available contacts */
	this->display_contacts();

	/* Ask the user to select a contact to display its details */
	while (i_contact < 0 || i_contact > this->_n_contact)
	{
		std::cout << std::endl;
		std::cout << "Please enter the index of the contact"
					 " whose details you want to see : ";
		std::cin >> buff;
		std::istringstream(buff) >> i_contact;
		if (i_contact > this->_n_contact)
		{
			std::cout << std::endl;
			std::cout << "This contact does not exist !" << std::endl;
			std::cout << std::endl;
		}
		else
		{
			/* Display the details of a given contact */
			this->contact[i_contact].get_contact_info();
			break ;
		}
	}
}

void	PhoneBook::display_contacts(void)
{
	int	i = 0;

	while(i < this->_n_contact)
	{
		std::cout << this->contact[i].get_contact_summary() << std::endl;
		i ++;
	}
}