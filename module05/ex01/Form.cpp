/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:35:29 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/10 11:13:38 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

Form::Form(void) :
	_name("Secret File"), _sign_state(false), _sign_grade(1), _exec_grade(1)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A Form has been created by the secretary." << std::endl;
	return ;
}

Form::Form(const std::string name, const int sign_grade, const int exec_grade) :
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

Form::Form(Form const &src) :
	_name(src.getName()), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
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

Form&		Form::operator=(Form const &src)
{
	this->_sign_state = src._sign_state;
	return (*this);
}

std::ostream&	operator<<(std::ostream &stream, Form const &Form)
{
	stream << "===== FORM INFOS =====" << std::endl
		   << "Name : " << Form.getName() << std::endl
		   << "Signed : " << Form.getSignState() << std::endl
		   << "Grade required to sign : " << Form.getSignGrade() << std::endl
		   << "Grade required to execute : " << Form.getExecGrade() << std::endl;
	return stream;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

const std::string	Form::getName(void) const
{
	return (this->_name);
}

bool				Form::getSignState(void) const
{
	return (this->_sign_state);
}

int					Form::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int					Form::getExecGrade(void) const
{
	return (this->_exec_grade);
}

void				Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw GradeTooHighException();
	else
		this->_sign_state = true;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ EXCEPTIONS ~~~                            */
/*                                                                            */
/* ************************************************************************** */

const char*			Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
}

const char*			Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

Form::~Form(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "A Form named " << this->_name
			  << " has been archived by the secretary." << std::endl;
	return ;
}
