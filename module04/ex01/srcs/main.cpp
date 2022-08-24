/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:01:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 12:15:18 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

int	main(void)
{
	// testLeaks();
	testDeepCopy();

	return (0);
}

void	testLeaks(void)
{
	std::cout << std::endl;
	std::cout << GREEN << "[TEST - LEAKS]" << std::endl;
	std::cout << std::endl;

	Animal	*animalTab[4];

	for (int i = 0; i < 2; i++)
	{
		animalTab[i] = new Dog();
		std::cout << std::endl;
	}

	for (int i = 2; i < 4; i++)
	{
		animalTab[i] = new Cat();
		std::cout << std::endl;
	}

	for (int i = 0; i < 4; i++)
		delete animalTab[i];

	return ;
}

void	testDeepCopy(void)
{
	std::cout << std::endl;
	std::cout << GREEN << "[SUBJECT TEST - COPY]" << END << std::endl;
	std::cout << std::endl;

	Dog	dog1;
	Dog	dog2;

	std::cout << std::endl;

	std::cout << YELLOW << "[BEFORE ASSIGNMENT] : " << END << std::endl;
	dog1.setDogIdea(42, "Mhhh I like this module !");
	std::cout << "Dog 1 : " << std::endl;
	std::cout << "\t";
	dog1.printIdea(42);
	std::cout << "Dog 2 : " << std::endl;
	std::cout << "\t";
	dog2.printIdea(42);

	std::cout << std::endl;

	dog2 = dog1;
	std::cout << YELLOW << "[AFTER ASSIGNMENT] : " << END << std::endl;
	std::cout << "Dog 1 : " << std::endl;
	std::cout << "\t";
	dog1.printIdea(42);
	std::cout << "Dog 2 : " << std::endl;
	std::cout << "\t";
	dog2.printIdea(42);

	std::cout << std::endl;

	Cat	cat1;

	std::cout << std::endl;

	std::cout << YELLOW << "[BEFORE COPY] : " << END << std::endl;
	cat1.setCatIdea(10, " Arf this module is shit !");
	std::cout << "Cat 1 : " << std::endl;
	std::cout << "\t";
	cat1.printIdea(10);
	std::cout << std::endl;

	std::cout << YELLOW << "[AFTER COPY] : " << END << std::endl;

	Cat	cat2(cat1);
	std::cout << "Cat 2 : " << std::endl;
	std::cout << "\t";
	cat2.printIdea(10);
	std::cout << std::endl;

	std::cout << YELLOW << "[BRAINS ARE INDEPENDENT] : " << END << std::endl;
	cat1.setCatIdea(42, " brainfuck !");
	std::cout << "Cat 1 : " << std::endl;
	std::cout << "\t";
	cat1.printIdea(42);
	std::cout << "Cat 2 : " << std::endl;
	std::cout << "\t";
	cat2.printIdea(42);

	std::cout << std::endl;
}