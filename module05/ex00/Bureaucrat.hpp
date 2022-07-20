/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:57:29 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/20 14:30:27 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

/* ************************************************************************** */
/*                                                                            */
/*                             ~~~ CLASSES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

class Bureaucrat
{
	public :
		/* constructors 		*/
							Bureaucrat(void);
							Bureaucrat(const std::string name, int grade);
							Bureaucrat(const Bureaucrat& src);
		/* operator overload	*/
		Bureaucrat			&operator=(const Bureaucrat& src);
		/* member functions */
		int					getGrade(void) const;
		const std::string	getName(void) const;
		void				upGrade(void);
		void				downGrade(void);
		/* exceptions 			*/
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		/* destructor 			*/
		virtual 			~Bureaucrat(void);

	private :

		const std::string	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);