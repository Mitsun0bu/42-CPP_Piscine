/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:01:10 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/18 19:20:54 by llethuil         ###   ########lyon.fr   */
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
	std::cout << "The newborn wrong animal is so wrong !" << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const &src)
{
	*this = src;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

WrongCat	&WrongCat::operator=(WrongCat const &src)
{
	this->_type = src.getType();
	return *this;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

WrongCat::~WrongCat(void)
{
		std::cout << "The animal that just died was just so wrong !" << std::endl;
	return ;
}
