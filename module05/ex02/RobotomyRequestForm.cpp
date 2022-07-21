/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:17:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/21 16:35:45 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(void) :
	A_Form("RobotomyRequestForm", 72, 45)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A RobotomyRequestForm has been created by the secretary." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	A_Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
				  << "The newly created form is a RobotomyRequestForm." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
	A_Form("RobotomyRequestForm", 72, 45)
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
			<< "A RobotomyRequestForm named " << src.getName()
			<< " has been duplicated !" << std::endl;
	*this = src;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

RobotomyRequestForm&		RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	this->_target = src._target;
	return *this;
}

std::ostream&	operator<<(std::ostream &stream, RobotomyRequestForm const &RobotomyRequestForm)
{
	std::string	signedMsg = "";
	if (RobotomyRequestForm.getSignState() == true)
		signedMsg = "Yes";
	else
		signedMsg = "No";
	stream << "===== ROBOTOMY REQUEST FORM INFOS =====" << std::endl
		   << "Name : " << RobotomyRequestForm.getName() << std::endl
		   << "Signed : " << signedMsg << std::endl
		   << "Grade required to sign : " << RobotomyRequestForm.getSignGrade() << std::endl
		   << "Grade required to execute : " << RobotomyRequestForm.getExecGrade() << std::endl;
	return stream;
}

/* ************************************************************************** */
/*                                                                            */
/*                        ~~~ OTHER MEMBER FUNCTIONS ~~~                      */
/*                                                                            */
/* ************************************************************************** */

void				RobotomyRequestForm::doFormJob(void) const
{
	static int i_call = 0;

	std::cout << "* DRILLING NOISE * ... " << std::endl;

	if (i_call % 2 == 0)
		std::cout << this->_target << " has been robotomized !" << std::endl;
	else
		std::cout << "The robotomy failed !" << std::endl;
	i_call ++;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "The newly archived form is a RobotomyRequestForm." << std::endl;
	return ;
}
