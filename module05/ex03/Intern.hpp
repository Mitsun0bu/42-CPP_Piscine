/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:35:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/21 19:08:03 by llethuil         ###   ########lyon.fr   */
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

class A_Form;

class Intern
{
	public :
		/* constructors			*/
				Intern(const std::string name, const std::string grade);
				Intern(const Intern& src);
		/* operator overload	*/
		Intern	&operator=(const Intern& src);
		/* member functions		*/
		A_Form	*makeForm(std::string name, std::string target);
		// faire un try/catch de A_Form::isValid avec le nom du form, si ca passe creer le form et le renvoyer

		/* destructor 			*/
		virtual	~Intern(void);

		private:
				Intern(void);
};