/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:08:58 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/10 12:08:24 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

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

class RobotomyRequestForm : public A_Form
{
	public :

		/* constructors																*/
								RobotomyRequestForm(void);
								RobotomyRequestForm(const std::string target);

		/* copy constructor															*/
								RobotomyRequestForm(const RobotomyRequestForm& src);

		/* member functions															*/
		virtual void			doFormJob(void) const;

		/* destructor																*/
		virtual 				~RobotomyRequestForm(void);

	private :

		/* private attribute														*/
		std::string			_target;

		/* operator overload
			private because const member attributes are not accessible				*/
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& src);
};

std::ostream&					operator<<(std::ostream& stream, const RobotomyRequestForm& RobotomyRequestForm);

# endif
