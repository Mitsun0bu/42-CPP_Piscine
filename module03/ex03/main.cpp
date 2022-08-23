/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:28:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/23 15:42:03 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diamondTrap1("DT1");
	DiamondTrap	diamondTrap2;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - INITILIZATION]" << END << std::endl;
	std::cout << diamondTrap1;
	std::cout << diamondTrap2;
	std::cout << std::endl;


	std::cout << GREEN << "[TEST - WHOAMI FUNCTION]" << END << std::endl;
	diamondTrap1.whoAmI();

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "[TEST - ATTACK FUNCTION INHERITED FROM SCAVTRAP]" << END << std::endl;
	diamondTrap1.attack("Laure Dure");

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - FUNCTIONS INHERITED FROM SCAVTRAP AND FRAGTRAP]" << END << std::endl;
	diamondTrap1.guardGate();
	diamondTrap1.highFivesGuys();

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - COPY CONSTRUCTOR]" << END << std::endl;
	std::cout << diamondTrap1;
	std::cout << std::endl;
	DiamondTrap	diamondTrap3(diamondTrap1);
	std::cout << std::endl;
	std::cout << diamondTrap3;

	std::cout << std::endl;

	return (0);
}