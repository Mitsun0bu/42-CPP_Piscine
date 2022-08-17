/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:22:48 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/08 18:22:08 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"
# include "easyfind.tpp"


int	main(void)
{
	int							intTab[] = {2, 4, 6, 8};
	std::list<int>				intList(intTab, intTab + sizeof(intTab) / sizeof(int) );
	std::list<int>::iterator	iter;

	std::cout << std::endl;
	std::cout << "CONTENT OF intList" << std::endl;
	for (iter = intList.begin(); iter != intList.end(); iter++)
		std::cout << *iter << ' ';
	std::cout << std::endl << std::endl;

	std::cout << "TEST - EASYFIND : FOUND" << std::endl;
	try
	{
		easyfind(intList, 6);
	}
	catch (NotFoundException &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	std::cout << "TEST - EASYFIND : NOT FOUND" << std::endl;
	try
	{
		easyfind(intList, 42);
	}
	catch (NotFoundException &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}