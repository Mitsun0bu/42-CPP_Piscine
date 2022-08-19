/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:55:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/19 11:51:13 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ CONSTRUCTORS ~~~                            */
/*                                                                            */
/* ************************************************************************** */

Fixed::Fixed(void) : _value(0)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "Default constructor called." << std::endl;

	return ;
}

Fixed::Fixed(const int to_convert)
{
		std::cout << BLUE << "[CONSTRUCTOR] : " << END
				  << "Int constructor called." << std::endl;

	/*
		To convert an int into fixed value:

		Do the following :  fixed = int^(fract_len)
		here			 :  fixed = int^(fract_len) = int^(8) = int << 8
	*/
	this->_value = to_convert << this->_frac_len;

	return ;
}

Fixed::Fixed(const float to_convert)
{
			std::cout << BLUE << "[CONSTRUCTOR] : " << END
					  << "Float constructor called." << std::endl;

	/*
		To convert a float into fixe value :

		Step 1:
			Do the following : fixed = float * 2^(fract_len)
			here			 : fixed = 2^(fract_len) = 2^8 = 1 << 8 = 1 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2
			(for every 1 on the right, you can multiply the value on the left by 2)
		Step 2:
			Round the value to the nearest integer
	*/
	this->_value = roundf(to_convert * (1 << this->_frac_len));

	return ;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
			  << "Copy constructor called." << std::endl;

	*this = src;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

Fixed	&Fixed::operator=(Fixed const &src)
{
	std::cout << YELLOW << "[ASSIGNMENT OPERATOR] : " << END
			  << "Assignation operator called." << std::endl;

	this->_value = src.getRawBits();

	return (*this);
}

Fixed	&Fixed::operator++(void)
{
	this->_value++;

	return (*this);
}

Fixed	Fixed::operator++(int inc)
{
	Fixed	temp = *this;
	(void)inc;

	++(*this);

	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	this->_value--;

	return (*this);
}

Fixed	Fixed::operator--(int inc)
{
	Fixed	temp = *this;
	(void)inc;

	--(*this);

	return (temp);
}

Fixed	Fixed::operator+(Fixed const &to_add) const
{
	float	addition;

	addition = this->toFloat() + to_add.toFloat();

	return (Fixed(addition));
}

Fixed	Fixed::operator-(Fixed const &to_substract) const
{
	float	subtraction;

	subtraction = this->toFloat() - to_substract.toFloat();

	return (Fixed(subtraction));
}

Fixed	Fixed::operator*(Fixed const &to_multiply) const
{
	float	multiplication;

	multiplication = this->toFloat() * to_multiply.toFloat();

	return (Fixed(multiplication));
}

Fixed	Fixed::operator/(Fixed const &to_divide) const
{
	float	division;

	division = this->toFloat() * to_divide.toFloat();

	return (Fixed(division));
}

bool	Fixed::operator>(Fixed const &to_compare) const
{
	if (this->_value > to_compare.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator<(Fixed const &to_compare) const
{
	if (this->_value < to_compare.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator>=(Fixed const &to_compare) const
{
	if (this->_value >= to_compare.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator<=(Fixed const &to_compare) const
{
	if (this->_value <= to_compare.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator==(Fixed const &to_compare) const
{
	if (this->_value == to_compare.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator!=(Fixed const &to_compare) const
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

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;

	return ;
}

float	Fixed::toFloat(void) const
{
	float result;

	result = (float)this->_value / (1 << this->_frac_len);

	return (result);
}

int	Fixed::toInt(void) const
{
	int result;

	result = (int)this->_value >> this->_frac_len;

	return (result);
}

Fixed&	Fixed::min(Fixed& n_1, Fixed& n_2)
{
	if (n_1 < n_2)
	   return (n_1);
	else
	   return (n_2);
}

const Fixed&	Fixed::min(const Fixed& n_1, const Fixed& n_2)
{
	if (n_1 < n_2)
	   return (n_1);
	else
	   return (n_2);
}

Fixed	&Fixed::max(Fixed& n_1, Fixed& n_2)
{
	if (n_1 > n_2)
	   return (n_1);
	else
	   return (n_2);
}

const Fixed&	Fixed::max(const Fixed& n_1, const Fixed& n_2)
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
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "Destructor called." << std::endl;

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

	return (stream);
}
