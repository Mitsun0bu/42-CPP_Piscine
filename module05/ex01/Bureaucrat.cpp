/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:57:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/20 12:04:14 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(void) : _name("Miss Kine"), _grade(150)
{
	std::cout << "A Bureaucrat has entered the office." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
	{
		this->_grade = grade;
		std::cout << "A Bureaucrat has entered the office." << std::endl;
	}
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

Bureaucrat&		Bureaucrat::operator=(Bureaucrat const &src)
{
	this->_grade = src._grade;
	return *this;
}

std::ostream&	operator<<(std::ostream &stream, Bureaucrat const &Bureaucrat)
{
	stream << Bureaucrat.getName() << ": Good morning sir !"
		   << " My name is " << Bureaucrat.getName()
		   << " and my bureaucrat grade is " << Bureaucrat.getGrade()
		   << std::endl;
	return stream;
}

/* ************************************************************************** */
/*                                                                            */
/*                        ~~~ OTHER MEMBER FUNCTIONS ~~~                      */
/*                                                                            */
/* ************************************************************************** */

int					Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

void				Bureaucrat::upGrade(void)
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
	{
		this->_grade--;
		std::cout << this->_name << " has been promoted !" << std::endl;
	}
	return ;
}

void				Bureaucrat::downGrade(void)
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
	{
		this->_grade++;
		std::cout << this->_name << " has been demoted !" << std::endl;
	}
	return ;
}

void				Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << "signed the "
				  << form.getName() << " form."
				  << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << "couldn't signed the "
				  << form.getName() << " form because "
				  << e.what() << std::endl;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "A Bureaucrat has left the office." << std::endl;
	return ;
}
