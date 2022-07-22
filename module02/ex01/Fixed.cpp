/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:55:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/21 18:47:20 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

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
                here, 2^fract_len = 2^8 = 1 << 8 = 1 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2
                (for every 1 on the right, you can multiply the value on the left by 2)
        Step 2: Round the value to the nearest integer
    */
    this->_value = roundf(to_convert * (1 << this->_frac_len));
    return ;
}

Fixed   &Fixed::operator=(Fixed const & src)
{
    std::cout << "Assignation operator called." << std::endl;
    this->_value = src.getRawBits();
    return (*this);
}

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

Fixed::~Fixed(void)
{
    std::cout << "Destructor called." << std::endl;
    return ;
}

std::ostream    &operator<<(std::ostream &stream, Fixed const &fix)
{
    stream << fix.toFloat();
    return stream;
}