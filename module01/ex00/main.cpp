/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:53:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/18 17:04:47 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <time.h>

# include "Zombie.hpp"

int	main(void)
{
	srand (time(NULL));

	std::string	nameList[4] = { "Rick", "Darryl", "Sarah", "Michonne" };
	std::string	name1;
	std::string	name2;

	name1 = nameList[rand() % 4] + " from Stack City";
	name2 = nameList[rand() % 4] + " from Heap City";

	/* Create a Zombie on the stack and make it announce himself */
	std::cout << GREEN << "[TEST] - randomChump()" << std::endl;
	std::cout << std::endl;
	randomChump(name1);
	std::cout << std::endl;

	/* The newZombie() function allocate a Zombie on the heap and return it */
	std::cout << GREEN << "[TEST] - newZombie()" << std::endl;
	std::cout << std::endl;

	Zombie	*heapZombie = newZombie(name2);
	heapZombie->announce();
	delete heapZombie;

	return (0);
}
