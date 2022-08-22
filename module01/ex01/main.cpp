/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:26:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/19 09:37:03 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <time.h>

# include "Zombie.hpp"

int main(void)
{
	/* Generate a random N number, which is the size of the horde */
	srand (time(NULL));

	int	N = rand() % 3 + 1;
	std::cout << GREEN << "[TEST] : " << END
			  << "The size of the Zombie horde is " << N << std::endl
			  << std::endl;

	/*
		The zombieHorde() function :
		- allocate N zombies on the heap
		- set the name of each zombie
	*/
	Zombie* horde = zombieHorde(N, "MegaHorde");
	std::cout << std::endl;

	/* All the zombie from the horde announce themself in this loop */
	for (int i = 0; i < N; i ++)
		horde[i].announce();
	std::cout << std::endl;

	/* The entire horde is deleted here */
	delete [] horde;

	return (0);
}