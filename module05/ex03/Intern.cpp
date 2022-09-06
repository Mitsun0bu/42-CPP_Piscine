/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:35:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/09/05 15:36:42 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

Intern::Intern(void)
{
	this->_formNameTab[0] = "Shrubbery Creation";
	this->_formNameTab[1] = "Robotomy Request";
	this->_formNameTab[2] = "Presidential Pardon";

	this->_funcTab[0] = &Intern::_makeShruberryCreationForm;
	this->_funcTab[1] = &Intern::_makeRobotomyRequestForm;
	this->_funcTab[2] = &Intern::_makePresidentialPardonForm;

	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "An Intern has entered the office." << std::endl;
	return ;
}

Intern::Intern(Intern const &src)
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
			  << "An Intern has been duplicated !" << std::endl;
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
	for (int i = 0; i < 3; i++)
		this->_formNameTab[i] = src._formNameTab[i];
	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

int	Intern::nameIsValid(const std::string &name)
{
	for (int i = 0; i < 3; i ++)
		if (this->_formNameTab[i] == name)
			return (i);
	throw InvalidNameException();
}

A_Form	*Intern::_makeShruberryCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

A_Form	*Intern::_makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

A_Form	*Intern::_makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

A_Form*	Intern::makeForm(std::string name, std::string target)
{
	try
	{
		int	i = 0;
		i = this->nameIsValid(name);
		return ((A_Form*)(this->*_funcTab[i])(target));
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "[EXCEPTION] : " << END
				  << e.what() << '\n';
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ EXCEPTIONS ~~~                            */
/*                                                                            */
/* ************************************************************************** */

const char*			Intern::InvalidNameException::what() const throw()
{
	return ("Form has an invalid name !");
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

Intern::~Intern(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "An Intern has left the office."
			  << std::endl;
	return ;
}
