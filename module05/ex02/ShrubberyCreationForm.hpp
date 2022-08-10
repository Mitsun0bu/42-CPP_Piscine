/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:19:01 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/10 12:10:07 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

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

		/* constructors																	*/
								ShrubberyCreationForm(void);
								ShrubberyCreationForm(const std::string target);

		/* copy constructor																*/
								ShrubberyCreationForm(const ShrubberyCreationForm& src);

		/* member functions																*/
		virtual void			doFormJob(void) const;

		/* destructor																	*/
		virtual 				~ShrubberyCreationForm(void);

	private :

		/* private attributes															*/
		std::string				_target;

		/* operator overload
			private because const member attributes are not accessible					*/
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& src);
};

std::ostream&					operator<<(std::ostream& stream, const ShrubberyCreationForm& ShrubberyCreationForm);

# endif
