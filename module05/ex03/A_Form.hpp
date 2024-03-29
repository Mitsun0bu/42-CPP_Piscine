/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Form.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:08:45 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/10 12:01:07 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                             ~~~ CLASSES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

class Bureaucrat;

class A_Form
{
	public :

		/* constructors																						*/
									A_Form(void);
									A_Form(const std::string name, const int sign_grade, const int exec_grade);

		/* copy constructor																					*/
									A_Form(const A_Form& src);

		/* member functions																					*/
		virtual const std::string	getName(void) const;
		virtual bool				getSignState(void) const;
		virtual int					getSignGrade(void) const;
		virtual int					getExecGrade(void) const;
		virtual void				beSigned(const Bureaucrat &bureaucrat);
		virtual void				execute(const Bureaucrat &bureaucrat) const;
		virtual void				doFormJob(void) const = 0;

		/* exceptions																						*/
		class						GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class						GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class						BureaucratGradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class						FormNotSignedException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		/* destructor																						*/
		virtual 					~A_Form(void);

	private :

		/* private attributes																				*/
		const std::string			_name;
		bool						_sign_state;
		const int					_sign_grade;
		const int					_exec_grade;

		/* operator overload
			private because const member attributes are not accessible										*/
		A_Form&				operator=(const A_Form& src);
};

std::ostream	&operator<<(std::ostream& stream, const A_Form& A_Form);

# endif
