/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:17:07 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/09 12:16:29 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

int	main(void)
{
	Span	intSpan(5);

	std::cout << std::endl;
	std::cout << "TEST - SPAN DECLARATION (size = 5)" << std::endl;
	std::cout << intSpan << std::endl;

	std::cout << "TEST - ADD NUMBERS" << std::endl;
	intSpan.addNumber(6);
	intSpan.addNumber(3);
	intSpan.addNumber(17);
	intSpan.addNumber(9);
	intSpan.addNumber(11);
	std::cout << intSpan << std::endl;

	std::cout << "TEST - FULL SPAN EXCEPTION" << std::endl;
	try
	{
		intSpan.addNumber(84);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "TEST - SHORTEST SPAN" << std::endl;
	std::cout << intSpan.shortestSpan() << std::endl;

	std::cout << std::endl;

	std::cout << "TEST - LONGEST SPAN" << std::endl;
	std::cout << intSpan.longestSpan() << std::endl;

	std::cout << std::endl;

	Span	singleSpan(1);

	std::cout << "TEST - SHORTEST SPAN ON singleSpan" << std::endl;
	try
	{
		std::cout << singleSpan.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	std::cout << "TEST - LONGEST SPAN ON singleSpan" << std::endl;
	try
	{
		std::cout << singleSpan.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;


	Span				rangeSpan(15000);

	std::vector<int>	vector(15000, 42);
	vector[67] = 50;
	vector[10] = 41;

	rangeSpan.addRange(vector.begin(), vector.end());
	std::cout << rangeSpan.shortestSpan() << std::endl;
	std::cout << rangeSpan.longestSpan() << std::endl;

	std::cout << std::endl;

	return (0);
}