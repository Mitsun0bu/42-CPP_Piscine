/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:53:30 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/11 11:44:49 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

int main(void)
{
    Fixed a;

    std::cout << "TEST INCREMENTATION / DECREMENTATION - START" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << "TEST INCREMENTATION / DECREMENTATION - END" << std::endl;
    std::cout << std::endl;

    Fixed       c(Fixed(2.04f) + Fixed (1.66f));
    Fixed const d(Fixed(2.04f) - Fixed (1.66f));
    Fixed       e(Fixed(2.04f) * Fixed (2));
    Fixed const f( Fixed(5.05f) / Fixed(2));

    std::cout << "TEST ADD, SUBTRACT, MULTIPLY, DIVIDE - START" << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "f = " << f << std::endl;
    std::cout << "TEST ADD, SUBTRACT, MULTIPLY, DIVIDE - END" << std::endl;
    std::cout << std::endl;

    std::cout << "TEST MIN / MAX - START" << std::endl;
    std::cout << Fixed::min(c, e) << std::endl;
    std::cout << Fixed::max(c, e) << std::endl;
    std::cout << "TEST MIN / MAX - END" << std::endl;
    std::cout << std::endl;

    std::cout << "TEST MIN / MAX CONST - START" << std::endl;
    std::cout << Fixed::min(c, d) << std::endl;
    std::cout << Fixed::max(c, d) << std::endl;
    std::cout << "TEST MIN / MAX CONST - END" << std::endl;

    return (0);
}
