/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:57:29 by llethuil          #+#    #+#             */
/*   Updated: 2022/09/06 11:05:14 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONVERTER_HPP
# define CONVERTER_HPP

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"
# include <cmath>

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

		// - to detect the type of the argument passed as parameter
		bool		argIsChar();
		bool		argIsInt();
		bool		argIsFloat();
		bool		argIsDouble();

		// - to handle argument depending on its type
		void	 	handleChar();
		void		handleInt();
		void		handleFloat();
		void		handleDouble();

		// - to get the string argument under char, int, float or double format
		void		argToChar();
		void		argToInt();
		void		argToFloat();
		void		argToDouble();

		// - to convert char argument to other types
		void		charToInt();
		void		charToFloat();
		void		charToDouble();

		// - to convert int argument to other types
		void		intToChar();
		void		intToFloat();
		void		intToDouble();

		// - to convert float argument to other types
		void		floatToChar();
		void		floatToInt();
		void		floatToDouble();

		// - to convert double argument to other types
		void		doubleToChar();
		void		doubleToInt();
		void		doubleToFloat();

		// - to print the output
		void	 	printCharValue();
		void		printIntValue();
		void		printFloatValue();
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

# endif