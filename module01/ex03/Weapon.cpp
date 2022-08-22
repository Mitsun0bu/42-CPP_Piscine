/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:25:53 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/22 09:38:07 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

Weapon::Weapon(void)
{
	std::cout << "A weapon of type * undefined * has been created !"
			  << std::endl;
	return ;
}

Weapon::Weapon(std::string type): _type(type)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A weapon of type * " << this->_type
			  << " * has been created !" << std::endl;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

std::string const &Weapon::getType(void)
{
	return (this->_type);
}

void		Weapon::setType(std::string newType)
{
	std::cout << "The " << this->_type
			  << " is replaced by a " << newType
			  << std::endl;

	this->_type = newType;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

Weapon::~Weapon()
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "A weapon has been destroyed !" << std::endl;

	return;
}