/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:11:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/10 12:04:56 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

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
		/* constructors 																*/
								PresidentialPardonForm(void);
								PresidentialPardonForm(const std::string target);

		/* copy constructor																*/
								PresidentialPardonForm(const PresidentialPardonForm& src);

		/* member functions																*/
		virtual void			doFormJob(void) const;

		/* destructor																	*/
		virtual 				~PresidentialPardonForm(void);

	private :

		/* private attributes															*/
		std::string			_target;

		/* operator overload
			private because const member attributes are not accessible					*/
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);
};

std::ostream&					operator<<(std::ostream& stream, const PresidentialPardonForm& PresidentialPardonForm);

# endif
