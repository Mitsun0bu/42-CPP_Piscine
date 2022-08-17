/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:18:27 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/08 15:32:03 by llethuil         ###   ########lyon.fr   */
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
	this->_nContact = 0;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

int		PhoneBook::addContact(int *i)
{
	if (*i >= 8)
		*i = 0;

	if (this->contact[*i].setContactInfo(*i) == FAIL)
		return (FAIL);

	if (this->_nContact < 8)
		this->_nContact++;

	return (SUCCESS);
}

int		PhoneBook::searchContact(void)
{
	if (_checkIfEmpty() == TRUE)
		return (SUCCESS);

	this->_displayContacts();

	if (_selectContact() == FAIL)
		return (FAIL);

	return (SUCCESS);
}

int		PhoneBook::_checkIfEmpty(void)
{
	if (this->_nContact == 0)
	{
		std::cout << std::endl;
		std::cout << "You don't have any contact in memory !" << std::endl;
		std::cout << std::endl;
		return (TRUE);
	}

	return (FALSE);
}

void	PhoneBook::_displayContacts(void)
{
	int	i = 0;

	while(i < this->_nContact)
	{
		std::cout << this->contact[i].getContactSummary() << std::endl;
		i ++;
	}

	return ;
}

int		PhoneBook::_selectContact(void)
{
	std::string	buff = "";
	int			i_contact = -1;

	while (i_contact < 0 || i_contact > this->_nContact)
	{
		std::cout << std::endl;

		std::cout << "Please enter the index of the contact"
					 " whose details you want to see : ";

		std::cin >> buff;
		if (std::cin.eof() == TRUE)
			return (FAIL);
		std::istringstream(buff) >> i_contact;

		if (i_contact > this->_nContact)
		{
			std::cout << std::endl;
			std::cout << "This contact does not exist !" << std::endl;
			std::cout << std::endl;
		}
		else
		{
			this->contact[i_contact].getContactInfo();
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

