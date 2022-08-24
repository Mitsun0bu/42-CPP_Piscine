/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:24:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 09:37:36 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

Animal::Animal(void) : _type("undefined")
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "An animal is born !" << std::endl;

	return ;
}

Animal::Animal(Animal const & src)
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

Animal&	Animal::operator=(Animal const & src)
{
	this->_type = src.getType();

	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
	std::cout << "Animal : \"Bruh.\"" << std::endl;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

Animal::~Animal(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "R.I.P. dear animal !" << std::endl;

	return ;
}
