/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:53:30 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/19 12:04:28 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

int main(void)
{
	Fixed a;

    std::cout << std::endl;

	std::cout << GREEN << "[TEST] - INCREMENTATION / DECREMENTATION" << END << std::endl;
    std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << std::endl;


	std::cout << GREEN << "[TEST] - ADD, SUBTRACT, MULTIPLY, DIVIDE" << END << std::endl;
	Fixed		c(Fixed(2.04f) + Fixed (1.66f));
	const Fixed d(Fixed(2.04f) - Fixed (1.66f));
	Fixed		e(Fixed(2.04f) * Fixed (2));
	const Fixed	f( Fixed(5.05f) / Fixed(2));

	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "[TEST] - MIN / MAX" << END << std::endl;
	std::cout << "Comparison between c and e" << std::endl;
	std::cout << "min : " << Fixed::min(c, e) << std::endl;
	std::cout << "max : " << Fixed::max(c, e) << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "[TEST] - MIN / MAX CONST" << END << std::endl;
	std::cout << "Comparison between c and d" << std::endl;
	std::cout << "min : " << Fixed::min(c, d) << std::endl;
	std::cout << "max : " << Fixed::max(c, d) << std::endl;
	std::cout << std::endl;

	return (0);
}
