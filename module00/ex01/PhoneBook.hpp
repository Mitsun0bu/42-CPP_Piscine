/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:28:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/08 16:11:03 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

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
		int		addContact(int *i);
		int		searchContact(void);
		/* destructor */
				~PhoneBook(void);

	private:
		/* private attributes */
		int		_nContact;
		int		_checkIfEmpty(void);
		void	_displayContacts(void);
		int		_selectContact(void);
};

# endif
