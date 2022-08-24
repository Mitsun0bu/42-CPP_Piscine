/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:01:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 15:04:35 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << GREEN << "[TEST - ANIMAL]" << END << std::endl;
	std::cout << std::endl;

	const Animal* animal1 = new Animal();
	const Animal* animal2 = new Dog();
	const Animal* animal3 = new Cat();


	std::cout << std::endl;
	std::cout << "Type : " << animal1->getType() << std::endl;
	std::cout << "Type : " << animal2->getType() << std::endl;
	std::cout << "Type : " << animal3->getType() << std::endl;

	std::cout << std::endl;
	animal1->makeSound();
	animal2->makeSound();
	animal3->makeSound();
	std::cout << std::endl;

	delete animal1;
	delete animal2;
	delete animal3;

	std::cout << std::endl;
	std::cout << GREEN << "[TEST - WRONG ANIMAL]" << END << std::endl;
	std::cout << std::endl;

	const WrongAnimal*	wrongAnimal1 = new WrongAnimal();
	const WrongAnimal*	wrongAnimal2 = new WrongCat();
	const WrongCat*		wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << "Type : " << wrongAnimal1->getType() << std::endl;
	std::cout << "Type : " << wrongAnimal2->getType() << std::endl;
	std::cout << "Type : " << wrongCat->getType() << std::endl;
	std::cout << std::endl;

	wrongAnimal1->makeSound();
	wrongAnimal2->makeSound();
	wrongCat->makeSound();
	std::cout << std::endl;

	delete wrongAnimal1;
	delete wrongAnimal2;
	delete wrongCat;

	return (0);
}
