/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:54:44 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/11 11:23:12 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

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

class Fixed
{
    public:

        Fixed(void);
        Fixed(Fixed const &src);
        Fixed(int const to_convert);
        Fixed(float const to_convert);
        int            getRawBits(void) const;
        void           setRawBits(int const raw);
        float          toFloat(void) const;
        int            toInt(void) const;
        static Fixed   min(Fixed &n_1, Fixed &n_2);
        static Fixed   min(Fixed const &n_1, Fixed const &n_2);
        static Fixed   max(Fixed &n_1, Fixed &n_2);
        static Fixed   max(Fixed const &n_1, Fixed const &n_2);
        Fixed          &operator=(Fixed const &src);
        Fixed          &operator++(void);      // Prefix increment operator
        Fixed          operator++(int inc);    // Postfix increment operator
        Fixed          &operator--(void);      // Prefix decrement operator
        Fixed          operator--(int inc);    // Postfix decrement operator
        Fixed          operator+(Fixed const &to_add) const;
        Fixed          operator-(Fixed const &to_subtract) const;
        Fixed          operator*(Fixed const &to_multiply) const;
        Fixed          operator/(Fixed const &to_divide) const;
        bool           operator>(Fixed const &to_compare);
        bool           operator<(Fixed const &to_compare);
        bool           operator>=(Fixed const &to_compare);
        bool           operator<=(Fixed const &to_compare);
        bool           operator==(Fixed const &to_compare);
        bool           operator!=(Fixed const &to_compare);
        ~Fixed();

    private:
        int                 _value;
        static int const    _frac_len = 8;
};

std::ostream    &operator<<(std::ostream &stream, Fixed const &fix);