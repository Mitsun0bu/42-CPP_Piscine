/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:01:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/19 15:03:47 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

int	main(void)
{
	/* TESTS ASKED IN THE SUBJECT */
	test_subject_array();
	test_subject_copy();
	/* SUBJECT LEAKS TEST */
	test_subject_leaks();
	/* MY TEST */
	my_test();

	return (0);
}

void	test_subject_array(void)
{
	std::cout << "===== SUBJECT TEST : ARRAY =====" << std::endl;

	Animal	*animal_tab[4];

	for (int i = 0; i < 4; i+=2)
	{
		animal_tab[i] = new Dog();
		std::cout << std::endl;
		animal_tab[i + 1] = new Cat();
		std::cout << std::endl;
	}

	for (int i = 0; i < 4; i++)
		delete animal_tab[i];

	return ;
}

void	test_subject_copy(void)
{
	std::cout << "===== SUBJECT TEST : COPY =====" << std::endl;

	Dog	dog_1;
	Dog	dog_2;
	Cat	cat_1;
	Cat	cat_2;

	std::cout << std::endl;
	dog_1.setDogIdea(42, "Mhhh I like this module !");
	dog_1.printIdea(42);
	dog_2.printIdea(42);

	dog_2 = dog_1;
	std::cout << std::endl << "After copy :" << std::endl;
	dog_1.printIdea(42);
	dog_2.printIdea(42);

	std::cout << std::endl;
	cat_1.setCatIdea(10, " Arf this module is shit !");
	cat_1.printIdea(10);
	cat_2.printIdea(10);

	cat_2 = cat_1;
	std::cout << std::endl << "After copy :" << std::endl;
	cat_1.printIdea(10);
	cat_2.printIdea(10);

	std::cout << std::endl;

}

void	test_subject_leaks(void)
{
	std::cout << "===== SUBJECT TEST : COPY =====" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	delete j;
	delete i;

	return ;
}

void	my_test(void)
{
	std::cout << "===== MY TEST =====" << std::endl;

	Dog	Lassie;
	Cat	Garfield;

	std::cout << std::endl << "Garfield has an idea : ";
	Garfield.printIdea(42);
	std::cout << std::endl;
	std::cout << std::endl << "Lassie has an idea : ";
	Lassie.printIdea(42);
	std::cout << std::endl;

	return ;
}