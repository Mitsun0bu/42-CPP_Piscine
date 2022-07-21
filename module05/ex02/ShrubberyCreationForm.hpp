/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:19:01 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/21 11:51:22 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


# pragma once

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "A_Form.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                             ~~~ CLASSES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

class Bureaucrat;

class ShrubberyCreationForm : public A_Form
{
	public :
		/* constructors 		*/
									ShrubberyCreationForm(void);
									ShrubberyCreationForm(const std::string target);
		/* member functions */
		virtual void				getSignState(void) const;
		virtual void				getExecState(void) const;
		/* destructor 			*/
		virtual 					~ShrubberyCreationForm(void);

	private :

		/* copy constructor 	*/
								ShrubberyCreationForm(const ShrubberyCreationForm& src); // private because const member attributes are not accessible
		/* operator overload	*/
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm& src); // private because const member attributes are not accessible
};

std::ostream	&operator<<(std::ostream& stream, const ShrubberyCreationForm& ShrubberyCreationForm);