/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:28:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/22 10:40:30 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ CLASSES ~~~                               */
/*                                                                            */
/* ************************************************************************** */

class PhoneBook
{
	public:
		/* constructor */
				PhoneBook(void);
		/* public attributes */
		Contact	contact[8];
		/* member functions */
		int		add_contact(int *i);
		int		search_contact(void);
		/* destructor */
				~PhoneBook(void);

	private:
		/* private attributes */
		int		_n_contact;
		int		_check_if_empty(void);
		void	_display_contacts(void);
		int		_select_contact(void);
};
