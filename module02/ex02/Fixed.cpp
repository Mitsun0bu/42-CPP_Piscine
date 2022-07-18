/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:55:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/13 10:10:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ CONSTRUCTORS ~~~                            */
/*                                                                            */
/* ************************************************************************** */

Fixed::Fixed(void)
{
    this->_value = 0;
    return ;
}

Fixed::Fixed(Fixed const &src)
{
    *this = src;
    return ;
}

Fixed::Fixed(int const to_convert)
{
    /*
        To convert an int into fixed value:

        Calculate fixed = int^fract_len
        here, int^fract_len = int^8 = int << 8
    */
    this->_value = to_convert << this->_frac_len;
    return ;
}

Fixed::Fixed(float const to_convert)
{
    /*
        To convert a float into fixe value :

        Step 1: Calculate fixed = float * 2^fract_len
                here, 2^fract_len = 2^8 = 1 << 8
        Step 2: Round the value to the nearest integer
    */
    this->_value = roundf(to_convert * (1 << this->_frac_len));
    return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

Fixed   &Fixed::operator=(Fixed const &src)
{
    this->_value = src.getRawBits();
    return *this;
}

Fixed   &Fixed::operator++(void)
{
    this->_value++;
    return *this;
}

Fixed   Fixed::operator++(int inc)
{
    Fixed   temp = *this;
    (void)inc;

    ++(*this);
    return (temp);
}

Fixed   &Fixed::operator--(void)
{
    this->_value--;
    return *this;
}

Fixed   Fixed::operator--(int inc)
{
    Fixed   temp = *this;
    (void)inc;

    --(*this);
    return (temp);
}

Fixed   Fixed::operator+(Fixed const &to_add) const
{
    float   addition;

    addition = this->toFloat() + to_add.toFloat();
    return (Fixed(addition));
}

Fixed   Fixed::operator-(Fixed const &to_substract) const
{
    float   subtraction;

    subtraction = this->toFloat() - to_substract.toFloat();
    return (Fixed(subtraction));
}

Fixed   Fixed::operator*(Fixed const &to_multiply) const
{
    float   multiplication;

    multiplication = this->toFloat() * to_multiply.toFloat();
    return (Fixed(multiplication));
}

Fixed   Fixed::operator/(Fixed const &to_divide) const
{
    float   division;

    division = this->toFloat() * to_divide.toFloat();
    return (Fixed(division));
}

bool    Fixed::operator>(Fixed const &to_compare) const
{
    if (this->_value > to_compare.getRawBits())
        return true;
    else
        return false;
}

bool    Fixed::operator<(Fixed const &to_compare) const
{
    if (this->_value < to_compare.getRawBits())
        return true;
    else
        return false;
}

bool    Fixed::operator>=(Fixed const &to_compare) const
{
    if (this->_value >= to_compare.getRawBits())
        return true;
    else
        return false;
}

bool    Fixed::operator<=(Fixed const &to_compare) const
{
    if (this->_value <= to_compare.getRawBits())
        return true;
    else
        return false;
}

bool    Fixed::operator==(Fixed const &to_compare) const
{
    if (this->_value == to_compare.getRawBits())
        return true;
    else
        return false;
}

bool    Fixed::operator!=(Fixed const &to_compare) const
{
    if (this->_value != to_compare.getRawBits())
        return true;
    else
        return false;
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ OTHER MEMBER FUNCTIONS ~~~                        */
/*                                                                            */
/* ************************************************************************** */

int     Fixed::getRawBits(void) const
{
    return (this->_value);
}

void    Fixed::setRawBits(int const raw)
{
    this->_value = raw;
    return ;
}

float   Fixed::toFloat(void) const
{
    float result;

    result = (float)this->_value / (1 << this->_frac_len);
    return (result);
}

int     Fixed::toInt(void) const
{
    int result;

    result = (int)this->_value >> this->_frac_len;
    return (result);
}

Fixed   &Fixed::min(Fixed &n_1, Fixed &n_2)
{
    if (n_1 < n_2)
        return (n_1);
    else
        return (n_2);
}

Fixed const &Fixed::min(Fixed const &n_1, Fixed const &n_2)
{
    if (n_1 < n_2)
        return (n_1);
    else
        return (n_2);
}

Fixed   &Fixed::max(Fixed &n_1, Fixed &n_2)
{
    if (n_1 > n_2)
        return (n_1);
    else
        return (n_2);
}

Fixed const &Fixed::max(Fixed const &n_1, Fixed const &n_2)
{
    if (n_1 > n_2)
        return (n_1);
    else
        return (n_2);
}

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ DESTRUCTOR ~~~                            */
/*                                                                            */
/* ************************************************************************** */

Fixed::~Fixed(void)
{
    return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                        ~~~ NON-MEMBER FUNCTIONS ~~~                        */
/*                                                                            */
/* ************************************************************************** */

std::ostream    &operator<<(std::ostream &stream, Fixed const &fix)
{
    stream << fix.toFloat();
    return stream;
}
