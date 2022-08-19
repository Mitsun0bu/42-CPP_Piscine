/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:54:44 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/19 10:51:54 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <cmath>

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
/*                              ~~~ CLASSES ~~~                               */
/*                                                                            */
/* ************************************************************************** */

class	Fixed
{
	public:

		/* constructors									*/
							Fixed(void);
							Fixed(const int to_convert);
							Fixed(const float to_convert);

		/* copy constructor								*/
							Fixed(const Fixed& src);

		/* operator overload							*/
		Fixed&				operator=(Fixed const &src);

		/* member functions								*/
		int					getRawBits(void) const;
		void				setRawBits(const int raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		/* destructor									*/
							~Fixed();

	private:

		/* private attributes							*/
		int					_value;
		static const int	_frac_len = 8;
};

std::ostream&	operator<<(std::ostream &stream, const Fixed& fix);

# endif