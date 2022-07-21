/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:27:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/21 11:41:55 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(void) : A_Form("ShruberryForm", 145, 137)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A ShrubberyForm has been created by the secretary." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : A_Form("ShruberryForm", 145, 137)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
				  << "The newly created form is a ShrubberyForm." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : A_Form("ShruberryForm", 145, 137)
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
			<< "A ShruberryForm named " << src.getName()
			<< " has been duplicated !" << std::endl;
	*this = src;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

ShrubberyCreationForm&		ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	return *this;
}

std::ostream&	operator<<(std::ostream &stream, ShrubberyCreationForm const &ShrubberyCreationForm)
{
	stream << "===== SHRUBERRY FORM INFOS =====" << std::endl
		   << "Name : " << ShrubberyCreationForm.getName() << std::endl
		   << "Signed : " << ShrubberyCreationForm.getSignState() << std::endl
		   << "Grade required to sign : " << ShrubberyCreationForm.getSignGrade() << std::endl
		   << "Grade required to execute : " << ShrubberyCreationForm.getExecGrade() << std::endl;
	return stream;
}

/* ************************************************************************** */
/*                                                                            */
/*                        ~~~ OTHER MEMBER FUNCTIONS ~~~                      */
/*                                                                            */
/* ************************************************************************** */

const std::string	ShrubberyCreationForm::getName(void) const
{
	;
	return (this->A_Form::getName());
}

bool				ShrubberyCreationForm::getSignState(void) const
{
	return (this->A_Form::getSignState());
}

int					ShrubberyCreationForm::getSignGrade(void) const
{
	return (this->getSignGrade());
}

int					ShrubberyCreationForm::getExecGrade(void) const
{
	return (this->getExecGrade());
}

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ EXCEPTIONS ~~~                            */
/*                                                                            */
/* ************************************************************************** */

const char*			ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
}

const char*			ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "A Form named " << this->_name
			  << " has been archived by the secretary." << std::endl;
	return ;
}
