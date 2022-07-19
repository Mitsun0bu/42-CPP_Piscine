/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:01:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/19 15:12:49 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

int	main(void)
{
	/* SUBJECT TEST */
	subject_test();
	/* MY TEST */
	my_test();

	return (0);
}

void	subject_test(void)
{
	std::cout << "===== SUBJECT TEST =====" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;

	i->makeSound(); // Will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	return ;
}

void	my_test(void)
{
	std::cout << "===== MY TEST =====" << std::endl;

	Animal		God;
	Dog			Lassie;
	Cat			Garfield;
	WrongAnimal	Experiment;
	WrongCat	Miaouss;

	std::cout << std::endl;
	std::cout << God.getType() << std::endl;
	God.makeSound();
	std::cout << std::endl;
	std::cout << Lassie.getType() << std::endl;
	Lassie.makeSound();
	std::cout << std::endl;
	std::cout << Garfield.getType() << std::endl;
	Garfield.makeSound();
	std::cout << std::endl;
	std::cout << Experiment.getType() << std::endl;
	Experiment.makeSound();
	std::cout << std::endl;
	std::cout << Miaouss.getType() << std::endl;
	Miaouss.makeSound();
	std::cout << std::endl;

	return ;
}