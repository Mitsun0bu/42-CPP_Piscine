/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:28:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/23 12:19:36 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	clapTrap1("CT1");
	ScavTrap	scavTrap1("ST1");
	ScavTrap	scavTrap2;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - INITILIZATION]" << END << std::endl;
	std::cout << clapTrap1;
	std::cout << scavTrap1;
	std::cout << scavTrap2;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - SET VALUES]" << END << std::endl;
	clapTrap1.setAttackDamage(10);
	scavTrap1.setAttackDamage(30);
	scavTrap2.setName("ST2");
	std::cout << std::endl;
	std::cout << clapTrap1;
	std::cout << scavTrap1;
	std::cout << scavTrap2;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - BATTLE (ROUND 1)]" << END << std::endl;
	scavTrap1.attack("CT1");
	clapTrap1.takeDamage(30);
	scavTrap2.guardGate();
	std::cout << std::endl;
	std::cout << clapTrap1;
	std::cout << scavTrap1;
	std::cout << scavTrap2;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - BATTLE (ROUND 2)]" << END << std::endl;
	clapTrap1.attack("ST1");
	clapTrap1.beRepaired(20);

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - \"=\" OPERATOR OVERLOAD]" << END << std::endl;
	scavTrap1 = scavTrap2;
	std::cout << scavTrap1;
	scavTrap1.setName("ST1");
	std::cout << scavTrap1;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - COPY]" << END << std::endl;
	ScavTrap	scavTrap3(scavTrap2);
	std::cout << scavTrap3;

	std::cout << std::endl;

	return (0);
}