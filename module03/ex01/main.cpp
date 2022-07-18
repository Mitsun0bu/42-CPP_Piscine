/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:28:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/18 10:45:57 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	clap_trap_1("CT1");
	ScavTrap	scav_trap_1("ST1");
	ScavTrap	scav_trap_2;

	std::cout << std::endl;

	std::cout << "TEST - INITILIZATION" << std::endl;
	std::cout << clap_trap_1;
	std::cout << scav_trap_1;
	std::cout << scav_trap_2;

	std::cout << std::endl;

	std::cout << "TEST - SET VALUES" << std::endl;
	clap_trap_1.set_ad(10);
	scav_trap_1.set_ad(30);
	scav_trap_2.set_name("ST2");
	std::cout << std::endl;
	std::cout << clap_trap_1;
	std::cout << scav_trap_1;
	std::cout << scav_trap_2;

	std::cout << std::endl;

	std::cout << "TEST - BATTLE [ROUND 1]" << std::endl;
	scav_trap_1.attack("CT1");
	clap_trap_1.takeDamage(30);
	scav_trap_2.guardGate();
	std::cout << std::endl;
	std::cout << clap_trap_1;
	std::cout << scav_trap_1;
	std::cout << scav_trap_2;

	std::cout << std::endl;

	std::cout << "TEST - BATTLE [ROUND 2]" << std::endl;
	clap_trap_1.attack("ST1");
	clap_trap_1.beRepaired(20);

	std::cout << std::endl;

	return (0);
}