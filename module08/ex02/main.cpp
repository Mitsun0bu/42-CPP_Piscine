/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:13:43 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/09 18:50:40 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

int	main(void)
{
	std::cout << std::endl;
	MutantStack<int>	mstack;
	std::cout << std::endl;

	std::cout << "TEST - PUSH VALUES TO STACK (5 | 17)" << std::endl;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Value at the top of the stack : " << mstack.top() << std::endl;
	std::cout << std::endl;

	std::cout << "TEST - POP ELEMENT FROM STACK" << std::endl;

	mstack.pop();
	std::cout << "Size of the stack : " << mstack.size() << std::endl;
	std::cout << std::endl;

	std::cout << "TEST - PUSH VALUES TO STACK (3 | 5 | 737 | 0)" << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Value at the top of the stack : " << mstack.top() << std::endl;
	std::cout << std::endl;

	std::cout << "TEST - STACK ITERATOR (++)" << std::endl;

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	std::cout << "~~~ Bottom of the stack ~~~" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "~~~ Top of the stack ~~~" << std::endl;
	std::cout << std::endl;

	std::cout << "TEST - STACK ITERATOR (--)" << std::endl;

	it --;
	std::cout << "~~~ Top of the stack ~~~" << std::endl;
	while (1)
	{
		std::cout << *it << std::endl;
		if (it == mstack.begin())
			break ;
		else
			--it;
	}
	std::cout << "~~~ Bottom of the stack ~~~" << std::endl;
	std::cout << std::endl;

	return 0;
}