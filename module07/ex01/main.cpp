/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:39:15 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/08 10:05:53 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"

int main(void)
{
	int			intTab[5] = {0, 1, 2, 3, 4};
	std::string	strTab[5] = {"Mitsunobu", "Mathilde", "Thomas"};
	char		charTab[5] = {'M', 'i', 't', 's', 'u'};

	std::cout << std::endl;
	std::cout << "TEST ITER TEMPLATE WITH INT TAB" << std::endl;
	::iter<int>(intTab, 5, printAnyTabContent<int>);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "TEST ITER TEMPLATE WITH STR TAB" << std::endl;
	::iter<std::string>(strTab, 3, printAnyTabContent<std::string>);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "TEST ITER TEMPLATE WITH CHAR TAB" << std::endl;
	::iter<char>(charTab, 5, printAnyTabContent<char>);
	std::cout << std::endl;

	std::cout << std::endl;

	return (0);
}
