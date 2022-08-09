/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:18:36 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/09 15:33:38 by llethuil         ###   ########lyon.fr   */
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

Span::Span(unsigned int N) : _intVector(N, 0), _spanSize(N)
{
	std::cout << std::endl << BLUE << "[CONSTRUCTOR] : " << END
				<< "A Span has been created." << std::endl;
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

Span&			Span::operator=(Span const & src)
{
	this->_intVector = src._intVector;
	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

void			Span::addNumber(int number)
{
	static unsigned int i = 0;

	if (i < this->_spanSize)
	{
		this->_intVector.at(i) = number;
		i ++;
	}
	else
		throw FullSpanException();
}

void			Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>::iterator	iter = begin;

	static unsigned int i = 0;

	while(iter < end)
	{
		if (i < this->_spanSize)
		{
			this->_intVector.at(i) = *iter;
			i ++;
			iter ++;
		}
		else
			throw FullSpanException();
	}

	i = 0;

	return ;
}

int				Span::shortestSpan()
{
	int					diff = INT_MAX;
	int					temp_diff = 0;
	unsigned int		i = -1;

	if (this->_spanSize == 1)
		throw InvalidSpanException();

	while(++i < this->_spanSize - 1)
	{
		if (this->_intVector.at(i) > this->_intVector.at(i + 1))
			temp_diff = this->_intVector.at(i) - this->_intVector.at(i + 1);
		else
			temp_diff = this->_intVector.at(i + 1) - this->_intVector.at(i);

		if(temp_diff < diff)
			diff = temp_diff;
	}
	return (diff);
}

int				Span::longestSpan()
{
	std::vector<int>	tempVector = this->_intVector;
	int					longestSpan = 0;

	if (this->_spanSize == 1)
		throw InvalidSpanException();

	sort(tempVector.begin(), tempVector.end(), std::greater<int>());

	longestSpan = tempVector.front() - tempVector.back();

	return (longestSpan);

}

unsigned int	Span::getSpanSize(void) const
{
	return (this->_spanSize);
}

int				Span::getValue(unsigned int i) const
{
	return (this->_intVector.at(i));
}

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ EXCEPTIONS ~~~                            */
/*                                                                            */
/* ************************************************************************** */

const char*		Span::InvalidSpanException::what() const throw()
{
	std::cout << RED << "[EXCEPTION] : " << END;
	return ("Error! The Span is invalid!");
}

const char*		Span::FullSpanException::what() const throw()
{
	std::cout << RED << "[EXCEPTION] : " << END;
	return ("Error! The Span is full!");
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

Span::~Span(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "A Span has been destructed." << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ NON-MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream &stream, Span const &Span)
{
	unsigned int i = -1;

	while (++i < Span.getSpanSize())
	{
		if (i == Span.getSpanSize() - 1)
			stream << Span.getValue(i);
		else
			stream << Span.getValue(i) << ", ";
	}
	stream << std::endl;
	return stream;
}