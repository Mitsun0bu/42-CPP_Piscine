/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:17:07 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/10 10:24:47 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

void	checkSpanInit(Span& span);
void	addNumbers(Span& span);
void	catchFullSpanException(Span& span);
void	testSpan(Span& span);
void	addSmallRange(Span& span);
void	addLargeRange(Span& span);

// What do we have to do with a Span full of 0's ???

int	main(void)
{
	Span	intSpan(5);

	std::cout << std::endl;
	checkSpanInit(intSpan);
	addNumbers(intSpan);
	catchFullSpanException(intSpan);
	testSpan(intSpan);

	Span	singleSpan(1);

	std::cout << std::endl;
	testSpan(singleSpan);


	Span	smallRangeSpan(10);

	std::cout << std::endl;

	addSmallRange(smallRangeSpan);
	testSpan(smallRangeSpan);

	Span	largeRangeSpan(15000);

	std::cout << std::endl;

	addLargeRange(largeRangeSpan);
	testSpan(largeRangeSpan);

	std::cout << std::endl;

	return (0);
}

void	checkSpanInit(Span& span)
{
	std::cout << "TEST - SPAN DECLARATION (size = 5)" << std::endl;

	std::cout << span << std::endl;

	return ;
}

void	addNumbers(Span& span)
{
	std::cout << "TEST - ADD NUMBER FUNCTION" << std::endl;

	span.addNumber(6);
	span.addNumber(3);
	span.addNumber(17);
	span.addNumber(9);
	span.addNumber(11);

	std::cout << span << std::endl;

	return ;
}

void	catchFullSpanException(Span& span)
{
	std::cout << "TEST - FULL SPAN EXCEPTION" << std::endl;

	try
	{
		span.addNumber(84);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	return ;
}

void	testSpan(Span& span)
{
	std::cout << "TEST - SHORTEST SPAN" << std::endl;

	try
	{
		std::cout << span.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	std::cout << "TEST - LONGEST SPAN" << std::endl;

	try
	{
		std::cout << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	return ;
}

void	addSmallRange(Span& span)
{
	std::cout << "TEST - ADD RANGE (small set)" << std::endl;

	std::vector<int>	testVector(10, 0);

	testVector[0] = 1;
	testVector[1] = 34;
	testVector[2] = 67;
	testVector[3] = 69;
	testVector[4] = 109;
	testVector[5] = 42;
	testVector[6] = 24;
	testVector[7] = 2;
	testVector[8] = 19;
	testVector[9] = 9;

	span.addRange(testVector.begin(), testVector.end());

	std::cout << span << std::endl;

	return ;
}

void	addLargeRange(Span& span)
{
	std::cout << "TEST - ADD RANGE (large set)" << std::endl;

	std::vector<int>	testVector(15000, 0);

	testVector[67] = 67;
	testVector[42] = 42;
	testVector[14999] = 9;

	span.addRange(testVector.begin(), testVector.end());

	std::cout << span << std::endl;

	return ;
}