/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:18:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/09 17:26:16 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPAN_HPP
# define SPAN_HPP

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <vector>
# include <limits>

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ COLOR DEFINES ~~~                           */
/*                                                                            */
/* ************************************************************************** */

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define END "\033[0m"

/* ************************************************************************** */
/*                                                                            */
/*                             ~~~ CLASSES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

class Span
{
	public :

		/* constructors 										*/
						Span(void);
						Span(unsigned int N);
						Span(Span& src);

		/* operator overload */
		Span&			operator=(Span const & src);

		/* member functions										*/
		void			addNumber(int number);
		void			addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int				shortestSpan();
		int				longestSpan();
		unsigned int	getSpanSize(void) const;
		int				getValue(unsigned int i) const;

		/* exceptions 											*/
		class	InvalidSpanException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class	FullSpanException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		/* destructor 											*/
						~Span(void);

	private :

		/* private attributes 									*/
		std::vector<int>	_intVector;
		unsigned int		_spanSize;
};

std::ostream	&operator<<(std::ostream &stream, Span const &Span);

# endif
