/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:57:29 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/03 17:52:18 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                             ~~~ CLASSES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

class Converter
{
	public :

		/* constructors 												*/
        			Converter(void);
        			Converter(std::string arg);
        			Converter(Converter& src);
        Converter&	operator=(Converter const & src);

		/* member functions												*/
		bool		argIsChar();
		bool		argIsInt();
		bool		argIsFloat();
		bool		argIsDouble();

		void	 	handleChar();
		void		argToChar();
		void	 	printCharValue();
		void		charToInt();
		void		charToFloat();
		void		charToDouble();

		void		handleInt();
		void		argToInt();
		void		intToChar();
		void		printIntValue();
		void		intToFloat();
		void		intToDouble();

		void		handleFloat();
		void		argToFloat();
		void		floatToChar();
		void		floatToInt();
		void		printFloatValue();
		void		floatToDouble();
		
		void		handleDouble();
		void		argToDouble();
		void		doubleToChar();
		void		doubleToInt();
		void		doubleToFloat();
		void		printDoubleValue();

		/* exceptions 													*/
		class 		OverflowException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class 		UnderflowException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class 		NonDisplayableException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class 		ImpossibleException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		
		/* destructor 													*/
		virtual 	~Converter(void);

	private :

		/* private attributes 													*/
		std::string	_arg;
		char		_char;
		int			_int;
		float		_float;
		double		_double; 
};