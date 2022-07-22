/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:18:27 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/22 10:42:20 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ CONSTRUCTOR ~~~                             */
/*                                                                            */
/* ************************************************************************** */

PhoneBook::PhoneBook(void)
{
	this->_n_contact = 0;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

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

int	PhoneBook::search_contact(void)
{
	if (_check_if_empty() == TRUE)
		return (SUCCESS);

	this->_display_contacts();

	if (_select_contact() == FAIL)
		return (FAIL);
	return (SUCCESS);
}

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

void	PhoneBook::_display_contacts(void)
{
	int	i = 0;

	while(i < this->_n_contact)
	{
		std::cout << this->contact[i].get_contact_summary() << std::endl;
		i ++;
	}
}

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

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

PhoneBook::~PhoneBook(void)
{
	return ;
}

