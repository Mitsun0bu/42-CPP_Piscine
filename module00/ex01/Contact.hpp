/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:28:33 by llethuil          #+#    #+#             */
/*   Updated: 2022/06/30 18:39:16 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <sstream>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		void		set_contact_info(int i);
		void		get_contact_info(void);
		std::string	get_contact_summary(void);

	private:
		int			_i;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_secret;
		std::string	format_str(std::string str);
};
