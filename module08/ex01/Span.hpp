/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:18:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/08 19:04:41 by llethuil         ###   ########lyon.fr   */
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
		Span&	operator=(Span const & src);

		/* member functions										*/
		void	addNumber();
		void	shortestSpan();
		void	longestSpan();

		/* exceptions 											*/
		class	InvalidParameterException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class	EmptySpanException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class	SoloSpanException : public std::exception
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
		virtual	~Span(void);

	private :

		/* private attributes 									*/
		std::vector<int>	_intVector;
};

# endif
