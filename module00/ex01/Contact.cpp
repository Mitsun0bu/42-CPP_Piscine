/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:21:57 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/30 18:59:38 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::set_contact_info(int i)
{
	this->_i = i;
	std::cout << std::endl;
	std::cout << "Please type the first name of the contact : ";
	std::cin >> this->_first_name;
	std::cout << "Please type the last name of the contact : ";
	std::cin >> this->_last_name;
	std::cout << "Please type the nickname of the contact : ";
	std::cin >> this->_nickname;
	std::cout << "Please type the phone number of the contact : ";
	std::cin >> this->_phone_number;
	std::cout << "Please type the darkest secret of the contact : ";
	std::cin >> this->_secret;
	std::cout << std::endl;
	std::cout << "The contact #" << i << " has been added successfully !" << std::endl;
	std::cout << std::endl;
}

void	Contact::get_contact_info()
{
	std::cout << std::endl;
	std::cout << "Contact index\t: " << this->_i << std::endl;
	std::cout << "First name\t: " << this->_first_name << std::endl;
	std::cout << "Last name\t: " << this->_last_name << std::endl;
	std::cout << "Nickname\t: " << this->_nickname << std::endl;
	std::cout << "Phone number\t: " << this->_phone_number << std::endl;
	std::cout << "Darkest secret\t: " << this->_secret << std::endl;
	std::cout << std::endl;
}

std::string	Contact::get_contact_summary()
{
	std::string			index;
	std::ostringstream	convert;
	std::string			str = "";

	/*
		Append each attribute, once formatted
		as specified in the subject, in str
	*/
	std::cout << std::endl;
	str.append("|");
	convert << this->_i;
	index = convert.str();
	str.append(format_str(index));
	str.append("|");
	str.append(format_str(this->_first_name));
	str.append("|");
	str.append(format_str(this->_last_name));
	str.append("|");
	str.append(format_str(this->_nickname));
	str.append("|");
	return str;
}

std::string	Contact::format_str(std::string str)
{
	std::string	result = "";

	/* Add whitespaces to str until it is 10 */
	if (str.length() < 10)
	{
		result = str;
		while(result.length() < 10)
			result = result.insert(0, " ");
	}
	/*
		Keep the 10th first characters of the str only
		and replace the last one by a dot
	*/
	else if (str.length() > 10)
	{
		result = str.substr(0, 10);
		result[9] = '.';
	}
	/*	Do nothing */
	else
		result = str;
	return result;
}