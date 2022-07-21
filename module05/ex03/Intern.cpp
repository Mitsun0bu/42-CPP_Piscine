/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:35:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/21 18:49:03 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

Intern::Intern(void)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A Intern has entered the office." << std::endl;
	return ;
}

Intern::Intern(const std::string name, const std::string grade)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
				<< "A Intern has entered the office." << std::endl;
	return ;
}

Intern::Intern(Intern const &src)
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
		<< "A Intern has been duplicated !" << std::endl;
	*this = src;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

Intern&		Intern::operator=(Intern const &src)
{
	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ EXCEPTIONS ~~~                            */
/*                                                                            */
/* ************************************************************************** */

const char*			Bureaucrat::GradeTooLowException::what() const throw()
{
	std::cout << RED << "[EXCEPTION] : " << END;
	return ("Bureaucrat grade is too low");
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

Bureaucrat::~Bureaucrat(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
		<< "A Bureaucrat named " << this->_name
		<< " has left the office." << std::endl;
	return ;
}
