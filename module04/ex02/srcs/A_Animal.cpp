/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:24:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 14:38:19 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

A_Animal::A_Animal(void) : _type("undefined")
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "An animal is born !" << std::endl;

	return ;
}

A_Animal::A_Animal(A_Animal const & src)
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

A_Animal&	A_Animal::operator=(A_Animal const & src)
{
	this->_type = src.getType();

	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

std::string	A_Animal::getType(void) const
{
	return (this->_type);
}

void	A_Animal::makeSound() const
{
	std::cout << "Animal : \"Bruh.\"" << std::endl;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

A_Animal::~A_Animal(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "R.I.P. dear animal !" << std::endl;

	return ;
}
