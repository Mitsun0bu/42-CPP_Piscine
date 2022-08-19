/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:54:44 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/19 10:54:43 by llethuil         ###   ########lyon.fr   */
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
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

# define FALSE 0
# define TRUE 1

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ CLASSES ~~~                               */
/*                                                                            */
/* ************************************************************************** */

class	Fixed
{
	public:

		/* constructors														*/
								Fixed(void);
								Fixed(const int to_convert);
								Fixed(const float to_convert);
		/* copy constructor													*/
								Fixed(const Fixed& src);

		/* operator overload												*/
		Fixed&					operator=(const Fixed& src);
		Fixed&					operator++(void);		// Prefix increment operator
		Fixed					operator++(int inc);	// Postfix increment operator
		Fixed&					operator--(void);		// Prefix decrement operator
		Fixed					operator--(int inc);	// Postfix decrement operator
		Fixed					operator+(const Fixed& to_add) const;
		Fixed					operator-(const Fixed& to_subtract) const;
		Fixed					operator*(const Fixed& to_multiply) const;
		Fixed					operator/(const Fixed& to_divide) const;
		bool					operator>(const Fixed& to_compare) const;
		bool					operator<(const Fixed& to_compare) const;
		bool					operator>=(const Fixed& to_compare) const;
		bool					operator<=(const Fixed& to_compare) const;
		bool					operator==(const Fixed& to_compare) const;
		bool					operator!=(const Fixed& to_compare) const;

		/* member functions													*/
		int						getRawBits(void) const;
		void					setRawBits(const int raw);
		float					toFloat(void) const;
		int						toInt(void) const;
		static Fixed&			min(Fixed& n_1, Fixed& n_2);
		static const Fixed&		min(const Fixed& n_1, const Fixed& n_2);
		static Fixed&			max(Fixed& n_1, Fixed& n_2);
		static const Fixed&		max(const Fixed& n_1, const Fixed& n_2);

		/* destructor									*/
								~Fixed();

	private:

		/* private attributes												*/
		int						_value;
		static const int		_frac_len = 8;
};

std::ostream&	operator<<(std::ostream &stream, const Fixed& fix);

# endif