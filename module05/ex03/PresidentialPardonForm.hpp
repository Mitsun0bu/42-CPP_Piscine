/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:11:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/22 11:36:18 by llethuil         ###   ########lyon.fr   */
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

class PresidentialPardonForm : public A_Form
{
	public :
		/* constructors 		*/
								PresidentialPardonForm(void);
								PresidentialPardonForm(const std::string target);
		/* member functions		*/
		virtual void			doFormJob(void) const;
		/* destructor			*/
		virtual 				~PresidentialPardonForm(void);

	private :

		/* copy constructor : private because const member attributes are not accessible */
								PresidentialPardonForm(const PresidentialPardonForm& src);
		/* operator overload : private because const member attributes are not accessible */
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);
		/* private attributes */
		std::string			_target;
};

std::ostream&					operator<<(std::ostream& stream, const PresidentialPardonForm& PresidentialPardonForm);