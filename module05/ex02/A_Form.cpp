/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Form.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:08:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/21 15:34:01 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "A_Form.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

A_Form::A_Form(void) :
	_name("Secret File"), _sign_state(false), _sign_grade(1), _exec_grade(1)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A Form has been created by the secretary." << std::endl;
	return ;
}

A_Form::A_Form(const std::string name, const int sign_grade, const int exec_grade) :
	_name(name), _sign_state(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	else
	{
		std::cout << BLUE << "[CONSTRUCTOR] : " << END
				  << "A Form has been created by the secretary." << std::endl;
	}
	return ;
}

A_Form::A_Form(A_Form const &src) :
	_sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
			<< "A Form named " << src.getName()
			<< " has been duplicated !" << std::endl;
	*this = src;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

A_Form&		A_Form::operator=(A_Form const &src)
{
	this->_sign_state = src._sign_state;
	return *this;
}

std::ostream&	operator<<(std::ostream &stream, A_Form const &A_Form)
{
	stream << "===== FORM INFOS =====" << std::endl
		   << "Name : " << A_Form.getName() << std::endl
		   << "Signed : " << A_Form.getSignState() << std::endl
		   << "Grade required to sign : " << A_Form.getSignGrade() << std::endl
		   << "Grade required to execute : " << A_Form.getExecGrade() << std::endl;
	return stream;
}

/* ************************************************************************** */
/*                                                                            */
/*                        ~~~ OTHER MEMBER FUNCTIONS ~~~                      */
/*                                                                            */
/* ************************************************************************** */

const std::string	A_Form::getName(void) const
{
	return (this->_name);
}

bool				A_Form::getSignState(void) const
{
	return (this->_sign_state);
}

int					A_Form::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int					A_Form::getExecGrade(void) const
{
	return (this->_exec_grade);
}

void				A_Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw GradeTooHighException();
	else
		this->_sign_state = true;
	return ;
}

void				A_Form::execute(const Bureaucrat& bureaucrat) const
{
	if (bureaucrat.getGrade() > this->_exec_grade)
		throw BureaucratGradeTooLowException();
	if (this->_sign_state == false)
		throw FormNotSignedException();
	else
		doFormJob();
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ EXCEPTIONS ~~~                            */
/*                                                                            */
/* ************************************************************************** */

const char*			A_Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low !");
}

const char*			A_Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high !");
}

const char*			A_Form::BureaucratGradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is too low !");
}

const char*			A_Form::FormNotSignedException::what() const throw()
{
	return ("Form has to be signed before execution !");
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

A_Form::~A_Form(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "A Form named " << this->_name
			  << " has been archived by the secretary." << std::endl;
	return ;
}
