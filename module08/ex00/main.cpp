/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:22:48 by llethuil          #+#    #+#             */
/*   Updated: 2022/09/08 11:30:43 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "easyFind.hpp"

int	main(void)
{
	int							intTab[] = {2, 4, 6, 8};
	std::list<int>				intList(intTab, intTab + sizeof(intTab) / sizeof(int) );
	std::list<int>::iterator	iter;
	std::vector<int> 			vect;

	std::cout << std::endl;
	std::cout << GREEN <<  "[CONTENT OF intList]" << END << std::endl;
	for (iter = intList.begin(); iter != intList.end(); iter++)
		std::cout << *iter << ' ';
	std::cout << std::endl << std::endl;

	std::cout << GREEN << "[TEST - EASYFIND : FOUND]" << END << std::endl;
	try
	{
		easyFind(intList, 6);
	}
	catch (NotFoundException &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - EASYFIND : NOT FOUND]" << END << std::endl;
	try
	{
		easyFind(intList, 42);
	}
	catch (NotFoundException &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - EASYFIND : NOT FOUND]" << END << std::endl;
	try
	{
		easyFind(vect, 6);
	}
	catch (NotFoundException &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}