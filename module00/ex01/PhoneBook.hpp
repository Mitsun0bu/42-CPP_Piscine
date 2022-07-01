/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:28:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/01 09:24:29 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "Contact.hpp"

# define TRUE 1
# define FALSE 0

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		Contact contact[8];
		void	add_contact(int *i);
		void	search_contact(void);
	private:
		int		_n_contact;
		int		_check_if_empty(void);
		void	_display_contacts(void);
		void	_select_contact(void);
};
