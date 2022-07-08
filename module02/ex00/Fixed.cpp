/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:55:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/08 09:49:38 by llethuil         ###   ########.fr       */
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

Fixed   &Fixed::operator=(Fixed const & src)
{
    std::cout << "Assignation operator called." << std::endl;
    this->_value = src.getRawBits();
    return *this;
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

Fixed::~Fixed(void)
{
    std::cout << "Destructor called." << std::endl;
    return ;
}