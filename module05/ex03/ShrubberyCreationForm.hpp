/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:19:01 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/21 16:14:56 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


# pragma once

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "A_Form.hpp"
# include <fstream>

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
		virtual void			doFormJob(void) const;
		/* destructor 			*/
		virtual 				~ShrubberyCreationForm(void);

	private :

		/* copy constructor : private because const member attributes are not accessible */
								ShrubberyCreationForm(const ShrubberyCreationForm& src);
		/* operator overload : private because const member attributes are not accessible */
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm& src);
		/* attributes */
		std::string				_target;
};

std::ostream					&operator<<(std::ostream& stream, const ShrubberyCreationForm& ShrubberyCreationForm);