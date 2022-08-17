/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:21:57 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/08 15:28:20 by llethuil         ###   ########lyon.fr   */
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

Contact::Contact(void)
{
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

int			Contact::setContactInfo(int i)
{
	this->_i = i;

	std::cout << std::endl;

	std::cout << "Enter the first name : ";
	std::cin >> this->_firstName;
	if (std::cin.eof() == TRUE)
		return (FAIL);

	std::cout << "Enter the last name : ";
	std::cin >> this->_lastName;
	if (std::cin.eof() == TRUE)
		return (FAIL);

	std::cout << "Enter the nickname : ";
	std::cin >> this->_nickName;
	if (std::cin.eof() == TRUE)
		return (FAIL);

	std::cout << "Enter the phone number : ";
	std::cin >> this->_phoneNumber;
	if (std::cin.eof() == TRUE)
		return (FAIL);

	std::cout << "Enter the darkest secret : ";
	std::cin >> this->_secret;
	if (std::cin.eof() == TRUE)
		return (FAIL);

	std::cout << std::endl;

	std::cout << "Contact #" << i << " added successfully !" << std::endl;

	std::cout << std::endl;

	return (SUCCESS);
}

void		Contact::getContactInfo() const
{
	std::cout << std::endl;

	std::cout << "Contact index\t: " << this->_i << std::endl;

	std::cout << "First name\t: " << this->_firstName << std::endl;

	std::cout << "Last name\t: " << this->_lastName << std::endl;

	std::cout << "Nickname\t: " << this->_nickName << std::endl;

	std::cout << "Phone number\t: " << this->_phoneNumber << std::endl;

	std::cout << "Darkest secret\t: " << this->_secret << std::endl;

	std::cout << std::endl;
}

std::string	Contact::getContactSummary() const
{
	std::string			index;
	std::ostringstream	convert;
	std::string			str = "";

	std::cout << std::endl;

	str.append("|");

	convert << this->_i;
	index = convert.str();
	str.append(_formatStr(index));

	str.append("|");

	str.append(_formatStr(this->_firstName));

	str.append("|");

	str.append(_formatStr(this->_lastName));

	str.append("|");

	str.append(_formatStr(this->_nickName));

	str.append("|");

	return str;
}

std::string	Contact::_formatStr(std::string str) const
{
	std::string	result = "";

	if (str.length() < 10)
	{
		result = str;
		while(result.length() < 10)
			result = result.insert(0, " ");
	}
	else if (str.length() > 10)
	{
		result = str.substr(0, 10);
		result[9] = '.';
	}
	else
		result = str;
	return result;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

Contact::~Contact(void)
{
	return ;
}
