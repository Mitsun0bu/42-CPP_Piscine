/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:18:27 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/01 15:42:01 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

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
int	PhoneBook::add_contact(int *i)
{
	if (*i >= 8)
		*i = 0;
	if (this->contact[*i].set_contact_info(*i) == FAIL)
		return (FAIL);
	if (this->_n_contact < 8)
		this->_n_contact++;
	return (SUCCESS);
}

/* This method allows the user to search for a contact in the phonebook */
int	PhoneBook::search_contact(void)
{
	if (_check_if_empty() == TRUE)
		return (SUCCESS);

	this->_display_contacts();

	if (_select_contact() == FAIL)
		return (FAIL);
	return (SUCCESS);
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
int	PhoneBook::_select_contact(void)
{
	std::string	buff = "";
	int			i_contact = -1;

	while (i_contact < 0 || i_contact > this->_n_contact)
	{
		std::cout << std::endl;
		std::cout << "Please enter the index of the contact"
					 " whose details you want to see : ";
		std::cin >> buff;
		if (std::cin.eof() == TRUE)
			return (FAIL);
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
	return (SUCCESS);
}
