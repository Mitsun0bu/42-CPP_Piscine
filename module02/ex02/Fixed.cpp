/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:55:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/08 15:20:25 by llethuil         ###   ########.fr       */
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
    std::cout << "Default constructor called." << std::endl;
    this->_value = 0;
    return ;
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = src;
    return ;
}

Fixed::Fixed(int const to_convert)
{
    std::cout << "Int constructor called." << std::endl;
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
    std::cout << "Float constructor called." << std::endl;
    
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
    std::cout << "Assignation operator called." << std::endl;
    this->_value = src.getRawBits();
    return *this;
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
    
    subtraction = this->_value - to_substract.toFloat();
    return (Fixed(subtraction));
}

Fixed   Fixed::operator*(Fixed const &to_multiply) const
{
    float   multiplication;
    
    multiplication = this->_value * to_multiply.toFloat();
    return (Fixed(multiplication));
}

Fixed   Fixed::operator/(Fixed const &to_divide) const
{
    float   division;
    
    division = this->_value * to_divide.toFloat();
    return (Fixed(division));
}

bool    &Fixed::operator>(Fixed const &to_compare)
{
    bool result;

    if (this->_value > to_compare.getRawBits())
        result = TRUE;
    else
        result = FALSE;
    return (result);
}

bool    &Fixed::operator<(Fixed const &to_compare)
{
    bool result;

    if (this->_value < to_compare.getRawBits())
        result = TRUE;
    else
        result = FALSE;
    return (result);
}

bool    &Fixed::operator>=(Fixed const &to_compare)
{
    bool result;

    if (this->_value >= to_compare.getRawBits())
        result = TRUE;
    else
        result = FALSE;
    return (result);
}

bool    &Fixed::operator<=(Fixed const &to_compare)
{
    bool result;

    if (this->_value <= to_compare.getRawBits())
        result = TRUE;
    else
        result = FALSE;
    return (result);
}

bool    &Fixed::operator==(Fixed const &to_compare)
{
    bool result;

    if (this->_value == to_compare.getRawBits())
        result = TRUE;
    else
        result = FALSE;
    return (result);
}

bool    &Fixed::operator!=(Fixed const &to_compare)
{
    bool result;

    if (this->_value != to_compare.getRawBits())
        result = TRUE;
    else
        result = FALSE;
    return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OTHER FUNCTIONS ~~~                           */
/*                                                                            */
/* ************************************************************************** */

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called." << std::endl;
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

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ DESTRUCTOR ~~~                            */
/*                                                                            */
/* ************************************************************************** */

Fixed::~Fixed(void)
{
    std::cout << "Destructor called." << std::endl;
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
