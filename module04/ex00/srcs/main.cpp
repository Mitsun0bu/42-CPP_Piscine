/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:01:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/19 09:37:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

int	main(void)
{
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

	return (0);
}