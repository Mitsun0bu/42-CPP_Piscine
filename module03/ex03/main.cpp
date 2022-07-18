/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:28:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/18 11:37:00 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	clap_trap_1("CT1");
	ScavTrap	scav_trap_1("ST1");
	FragTrap	frag_trap_1("FT1");
	DiamondTrap	diamond_trap_1("DT1");
	// DiamondTrap	diamond_trap_2;

	std::cout << std::endl;

	std::cout << "TEST - INITILIZATION" << std::endl;
	std::cout << clap_trap_1;
	std::cout << scav_trap_1;
	std::cout << frag_trap_1;
	std::cout << diamond_trap_1;
	// std::cout << diamond_trap_2;
	diamond_trap_1.whoAmI();
	// std::cout << diamond_trap_2.whoAmI();


	std::cout << std::endl;

	// std::cout << "TEST - SET VALUES" << std::endl;
	// clap_trap_1.set_ad(10);
	// frag_trap_1.set_ad(2);
	// frag_trap_2.set_name("Suicune");
	// std::cout << std::endl;
	// std::cout << clap_trap_1;
	// std::cout << frag_trap_1;
	// std::cout << frag_trap_2;

	// std::cout << std::endl;

	// std::cout << "TEST - BATTLE [ROUND 1]" << std::endl;
	// frag_trap_1.attack("Charmander");
	// clap_trap_1.takeDamage(2);
	// frag_trap_2.highFivesGuys();
	// std::cout << std::endl;
	// std::cout << clap_trap_1;
	// std::cout << frag_trap_1;
	// std::cout << frag_trap_2;

	std::cout << std::endl;

	return (0);
}