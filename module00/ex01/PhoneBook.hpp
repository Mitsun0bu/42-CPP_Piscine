/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:28:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/01 15:41:34 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "main.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		Contact contact[8];
		int		add_contact(int *i);
		int		search_contact(void);

	private:
		int		_n_contact;
		int		_check_if_empty(void);
		void	_display_contacts(void);
		int		_select_contact(void);
};
