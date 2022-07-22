/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:12:05 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/22 10:49:50 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(void) :
	A_Form("PresidentialPardonForm", 25, 5)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A PresidentialPardonForm has been created by the secretary." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	A_Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
				  << "The newly created form is a PresidentialPardonForm." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
	A_Form("PresidentialPardonForm", 25, 5)
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
			<< "A PresidentialPardonForm named " << src.getName()
			<< " has been duplicated !" << std::endl;
	*this = src;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

PresidentialPardonForm&		PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	this->_target = src._target;
	return (*this);
}

std::ostream&	operator<<(std::ostream &stream, PresidentialPardonForm const &PresidentialPardonForm)
{
	std::string	signedMsg = "";
	if (PresidentialPardonForm.getSignState() == true)
		signedMsg = "Yes";
	else
		signedMsg = "No";
	stream << "===== PRESIDENTIAL PARDON FORM INFOS =====" << std::endl
		   << "Name : " << PresidentialPardonForm.getName() << std::endl
		   << "Signed : " << signedMsg << std::endl
		   << "Grade required to sign : " << PresidentialPardonForm.getSignGrade() << std::endl
		   << "Grade required to execute : " << PresidentialPardonForm.getExecGrade() << std::endl;
	return stream;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

void				PresidentialPardonForm::doFormJob(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox !" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "The PresidentialPardonForm can be archived." << std::endl;
	return ;
}
