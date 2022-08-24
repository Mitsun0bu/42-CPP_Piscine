/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:01:10 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 10:35:52 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

WrongCat::WrongCat(void)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "The newborn wrong animal is a wrong cat !" << std::endl;

	return ;
}

WrongCat::WrongCat(WrongCat const & src)
{
	*this = src;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

WrongCat&	WrongCat::operator=(WrongCat const & src)
{
	this->_type = src.getType();

	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

void	WrongCat::makeSound() const
{
	std::cout << "Wrong cat : \"COINCOIN !\"" << std::endl;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

WrongCat::~WrongCat(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "A wrong cat just died !" << std::endl;

	return ;
}
