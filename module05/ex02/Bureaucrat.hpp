/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:57:29 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/21 11:21:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Form.hpp"

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

class Form;

class Bureaucrat
{
	public :
		/* constructors 		*/
							Bureaucrat(void);
							Bureaucrat(const std::string name, int grade);
		/* member functions */
		int					getGrade(void) const;
		const std::string	getName(void) const;
		void				upGrade(void);
		void				downGrade(void);
		void				signForm(Form& form) const;
		/* exceptions 			*/
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		/* destructor 			*/
		virtual 			~Bureaucrat(void);

	private :

		/* copy constructor 	*/
							Bureaucrat(const Bureaucrat& src); // private because const member attributes are not accessible
		/* operator overload	*/
		Bureaucrat			&operator=(const Bureaucrat& src); // private because const member attributes are not accessible
		/* attributes */
		const std::string	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);