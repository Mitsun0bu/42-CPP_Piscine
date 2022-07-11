/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:28:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/11 18:46:18 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	clap_trap_1("Charmander");
	ScavTrap	scav_trap_1("Mewtwo");
	ScavTrap	scav_trap_2;

	std::cout << std::endl;

	std::cout << "TEST - INITILIZATION" << std::endl;
	std::cout << clap_trap_1;
	std::cout << scav_trap_1;
	std::cout << scav_trap_2;

	std::cout << std::endl;

	std::cout << "TEST - SET VALUES" << std::endl;
	clap_trap_1.set_ad(10);
	scav_trap_1.set_ad(2);
	scav_trap_2.set_name("Mr. Nooo");
	std::cout << std::endl;
	std::cout << clap_trap_1;
	std::cout << scav_trap_1;
	std::cout << scav_trap_2;

	std::cout << std::endl;

	std::cout << "TEST - BATTLE [ROUND 1]" << std::endl;
	scav_trap_1.attack("Charmander");
	clap_trap_1.takeDamage(2);
	scav_trap_2.guardGate();
	std::cout << std::endl;
	std::cout << clap_trap_1;
	std::cout << scav_trap_1;
	std::cout << scav_trap_2;

	std::cout << std::endl;

	return (0);
}