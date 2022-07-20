/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:28:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/20 16:29:59 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diamond_trap_1("DT1");
	DiamondTrap	diamond_trap_2;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - INITILIZATION]" << END << std::endl;
	std::cout << diamond_trap_1;
	std::cout << diamond_trap_2;
	std::cout << std::endl;


	std::cout << GREEN << "[TEST - WHOAMI FUNCTION]" << END << std::endl;
	diamond_trap_1.whoAmI();

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "[TEST - ATTACK FUNCTION INHERITED FROM SCAVTRAP]" << END << std::endl;
	diamond_trap_1.attack("Laure Dure");

	std::cout << std::endl;

	return (0);
}