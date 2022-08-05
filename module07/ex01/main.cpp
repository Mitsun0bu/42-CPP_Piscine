/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:39:15 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/05 16:45:39 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"

int main(void)
{
	int			intTab[5] = {0, 1, 2, 3, 4};
	std::string	strTab[5] = {"Mitsunobu", "Mathilde", "Thomas"};
	char        charTab[5] = {'M', 'i', 't', 's', 'u'};

    std::cout << std::endl;
    std::cout << "TEST ITER TEMPLATE WITH INT TAB" << std::endl;
	::iter<int>(intTab, 5, printAnyTabContent);
	std::cout << std::endl;

	std::cout << std::endl;
    std::cout << "TEST ITER TEMPLATE WITH STR TAB" << std::endl;
	::iter<std::string>(strTab, 3, printAnyTabContent);
	std::cout << std::endl;

	std::cout << std::endl;
    std::cout << "TEST ITER TEMPLATE WITH CHAR TAB" << std::endl;
	::iter<char>(charTab, 5, printAnyTabContent);
	std::cout << std::endl;
	
    std::cout << std::endl;

	return (0);
}
