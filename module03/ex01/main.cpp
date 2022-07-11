/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:28:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/11 16:28:27 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clap_trap_1("Charmander");
	ClapTrap	clap_trap_2("Bulbasaur");
	ClapTrap	clap_trap_3;

	std::cout << std::endl;

	std::cout << "TEST - INITILIZATION" << std::endl;
	std::cout << clap_trap_1;
	std::cout << clap_trap_2;
	std::cout << clap_trap_3;

	std::cout << std::endl;

	std::cout << "TEST - SET VALUES" << std::endl;
	clap_trap_1.set_ad(10);
	clap_trap_2.set_ad(2);
	clap_trap_3.set_name("Squirtle");
	clap_trap_3.set_ep(0);
	std::cout << std::endl;
	std::cout << clap_trap_1;
	std::cout << clap_trap_2;
	std::cout << clap_trap_3;

	std::cout << std::endl;

	std::cout << "TEST - BATTLE [ROUND 1]" << std::endl;
	clap_trap_1.attack("Bulbasaur");
	clap_trap_2.takeDamage(10);
	clap_trap_3.attack("Bulbasaur");
	std::cout << std::endl;
	std::cout << clap_trap_1;
	std::cout << clap_trap_2;
	std::cout << clap_trap_3;

	std::cout << std::endl;

	std::cout << "TEST - BATTLE [ROUND 2]" << std::endl;
	clap_trap_1.beRepaired(5);
	clap_trap_2.attack("Charmander");
	clap_trap_3.beRepaired(2);
	std::cout << std::endl;
	std::cout << clap_trap_1;
	std::cout << clap_trap_2;
	std::cout << clap_trap_3;

	std::cout << std::endl;

	return (0);
}