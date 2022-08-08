/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:18:36 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/08 19:08:09 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"


/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

Span::Span(void)
{
	std::cout << std::endl << BLUE << "[CONSTRUCTOR] : " << END
			  << "A Span has been created." << std::endl
			  << std::endl;
	return ;
}

Span::Span(unsigned int N)
{
	std::cout << std::endl << BLUE << "[CONSTRUCTOR] : " << END
				<< "A Span has been created." << std::endl
				<< std::endl;

	if (N <= UINT_MAX)
		this->_intVector(N, 0);
	else
		throw InvalidParameterException();
	return ;
}

Span::Span(Span& src)
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
	<< "A Converter has been duplicated !" << std::endl
	<< std::endl;

	*this = src;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

Span& Span::operator=(Span const & src)
{
	this->_intVector = src._intVector;
	return (*this);
}