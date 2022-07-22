/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:35:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/22 13:49:35 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "A_Form.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ COLOR DEFINES ~~~                           */
/*                                                                            */
/* ************************************************************************** */

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define END "\033[0m"

/* ************************************************************************** */
/*                                                                            */
/*                             ~~~ CLASSES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

class	A_Form;

class Intern
{
	public :
		/* constructors			*/
								Intern(void);
								Intern(const Intern& src);
		/* operator overload	*/
		Intern&					operator=(const Intern& src);
		/* member functions		*/
		int						nameIsValid(const std::string &name);
		A_Form*					makeForm(std::string name, std::string target);
		/* exceptions			*/
		class InvalidNameException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		/* destructor 			*/
		virtual					~Intern(void);

	private:

		std::string				_formNameTab[3];
		void					_makeSF();
		void					_makeRR();
		void					_makePP();
		void					(Intern::*_funcTab[3])(void);
};