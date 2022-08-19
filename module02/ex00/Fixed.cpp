/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:55:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/19 10:19:48 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

Fixed::Fixed(void) : _value(0)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "Default constructor called." << std::endl;

	return ;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
			  << "Copy constructor called." << std::endl;

	*this = src;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

Fixed	&Fixed::operator=(Fixed const & src)
{
	std::cout << YELLOW << "[ASSIGNMENT OPERATOR] : " << END
			  << "Copy assignment operator called." << std::endl;

	this->_value = src.getRawBits();

	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

int	Fixed::getRawBits(void) const
{
	std::cout << GREEN << "[TEST] - getRawBits : " << END
			  << "getRawBits member function called." << std::endl;

	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

Fixed::~Fixed(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "Destructor called." << std::endl;

	return ;
}