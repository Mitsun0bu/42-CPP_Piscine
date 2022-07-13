/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:28:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/13 10:50:47 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	clap_trap_1("Charizard");
	FragTrap	frag_trap_1("Lugia");
	FragTrap	frag_trap_2;

	std::cout << std::endl;

	std::cout << "TEST - INITILIZATION" << std::endl;
	std::cout << clap_trap_1;
	std::cout << frag_trap_1;
	std::cout << frag_trap_2;

	std::cout << std::endl;

	std::cout << "TEST - SET VALUES" << std::endl;
	clap_trap_1.set_ad(10);
	frag_trap_1.set_ad(2);
	frag_trap_2.set_name("Suicune");
	std::cout << std::endl;
	std::cout << clap_trap_1;
	std::cout << frag_trap_1;
	std::cout << frag_trap_2;

	std::cout << std::endl;

	std::cout << "TEST - BATTLE [ROUND 1]" << std::endl;
	frag_trap_1.attack("Charmander");
	clap_trap_1.takeDamage(2);
	frag_trap_2.highFivesGuys();
	std::cout << std::endl;
	std::cout << clap_trap_1;
	std::cout << frag_trap_1;
	std::cout << frag_trap_2;

	std::cout << std::endl;

	return (0);
}