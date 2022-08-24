/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:19:02 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 09:42:21 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

WrongAnimal::WrongAnimal(void) : _type("wrong")
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A wrong animal is born !" << std::endl;

	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
			  << "An animal has been duplicated !" << std::endl;

	*this = src;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const & src)
{
	this->_type = src.getType();

	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong animal : \"Booyashakaaa !\"" << std::endl;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

WrongAnimal::~WrongAnimal(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "The animal that died was just so wrong !" << std::endl;

	return ;
}
