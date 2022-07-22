/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:35:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/22 13:49:00 by llethuil         ###   ########lyon.fr   */
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

	this->_funcTab[0] = &Intern::_makeSF;
	this->_funcTab[1] = &Intern::_makeRR;
	this->_funcTab[2] = &Intern::_makePP;

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

A_Form*	Intern::makeForm(std::string name, std::string target)
{
	try
	{
		int	i;

		i = this->nameIsValid(name);
		return ((void)(this->*_funcTab[i])());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


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
