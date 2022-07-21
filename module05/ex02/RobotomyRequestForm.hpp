/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:08:58 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/21 16:15:02 by llethuil         ###   ########lyon.fr   */
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

class RobotomyRequestForm : public A_Form
{
	public :
		/* constructors 		*/
							RobotomyRequestForm(void);
							RobotomyRequestForm(const std::string target);
		/* member functions */
		virtual void		doFormJob(void) const;
		/* destructor 			*/
		virtual 			~RobotomyRequestForm(void);

	private :

		/* copy constructor : private because const member attributes are not accessible */
							RobotomyRequestForm(const RobotomyRequestForm& src);
		/* operator overload : private because const member attributes are not accessible */
		RobotomyRequestForm	&operator=(const RobotomyRequestForm& src);
		/* attributes */
		std::string			_target;
};

std::ostream				&operator<<(std::ostream& stream, const RobotomyRequestForm& RobotomyRequestForm);