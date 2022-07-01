/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:18:27 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/01 09:29:44 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <sstream>
# include "PhoneBook.hpp"

/* Constructor of PhoneBook class */
PhoneBook::PhoneBook(void)
{
	this->_n_contact = 0;
	return ;
}

/* Destructor of PhoneBook class */
PhoneBook::~PhoneBook(void)
{
	return ;
}

/* This method allows the user to add a contact to the phonebook */
void	PhoneBook::add_contact(int *i)
{
	if (*i >= 8)
		*i = 0;
	this->contact[*i].set_contact_info(*i);
	if (this->_n_contact < 8)
		this->_n_contact++;
}

/* This method allows the user to search for a contact in the phonebook */
void	PhoneBook::search_contact(void)
{
	if (_check_if_empty() == TRUE)
		return ;

	this->_display_contacts();

	_select_contact();
}

/* This method check if the phonebook is empty */
int	PhoneBook::_check_if_empty(void)
{
	if (this->_n_contact == 0)
	{
		std::cout << std::endl;
		std::cout << "You don't have any contact in memory !" << std::endl;
		std::cout << std::endl;
		return (TRUE);
	}
	return (FALSE);
}

/* This method display the contacts that are available in the phonebook */
void	PhoneBook::_display_contacts(void)
{
	int	i = 0;

	while(i < this->_n_contact)
	{
		std::cout << this->contact[i].get_contact_summary() << std::endl;
		i ++;
	}
}

/* This method ask the user to select a contact to display its details */
void	PhoneBook::_select_contact(void)
{
	std::string	buff = "";
	int			i_contact = -1;

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
			this->contact[i_contact].get_contact_info();
			break ;
		}
	}
}
