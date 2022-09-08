/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:13:43 by llethuil          #+#    #+#             */
/*   Updated: 2022/09/08 14:05:11 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

int	main(void)
{
	std::cout << std::endl;
	MutantStack<int>	mstack;
	std::cout << std::endl;

	std::cout << GREEN << "[TEST - PUSH VALUES TO STACK (5 | 17)]" << END << std::endl;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Value at the top of the stack : " << mstack.top() << std::endl;
	std::cout << "Size of the stack : " << mstack.size() << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "[TEST - POP ELEMENT FROM STACK (5)]" << END << std::endl;

	mstack.pop();
	std::cout << "Value at the top of the stack : " << mstack.top() << std::endl;
	std::cout << "Size of the stack : " << mstack.size() << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "[TEST - PUSH VALUES TO STACK (5 | 3 | 5 | 737 | 0)]" << END << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Value at the top of the stack : " << mstack.top() << std::endl;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - STACK ITERATOR (++)]" << END << std::endl;

	MutantStack<int>::iterator	iter1 = mstack.begin();
	MutantStack<int>::iterator	iter2 = mstack.end();
	std::cout << "~~~ Bottom of the stack ~~~" << std::endl;
	while (iter1 != iter2)
	{
		std::cout << *iter1 << std::endl;
		++iter1;
	}
	std::cout << "~~~ Top of the stack ~~~" << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "[TEST - STACK ITERATOR (--)]" << END << std::endl;

	iter1 --;
	std::cout << "~~~ Top of the stack ~~~" << std::endl;
	while (1)
	{
		std::cout << *iter1 << std::endl;
		if (iter1 == mstack.begin())
			break ;
		else
			--iter1;
	}
	std::cout << "~~~ Bottom of the stack ~~~" << std::endl;
	std::cout << std::endl;

	return 0;
}