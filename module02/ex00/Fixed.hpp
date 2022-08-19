/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:54:44 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/19 09:56:48 by llethuil         ###   ########lyon.fr   */
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

		/* constructor									*/
							Fixed(void);

		/* copy constructor								*/
							Fixed(Fixed const &src);

		/* operator overload							*/
		Fixed&				operator=(Fixed const &src);

		/* member functions								*/
		int					getRawBits(void) const;
		void				setRawBits(int const raw);

		/* destructor									*/
							~Fixed(void);

	private:

		/* private attributes							*/
		int					_value;
		static int const	_frac_len = 8;
};

# endif