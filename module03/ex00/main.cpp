/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:28:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/23 12:19:11 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clapTrap1("CT1");
	ClapTrap	clapTrap2("CT2");
	ClapTrap	clapTrap3;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - INITILIZATION]" << END << std::endl;
	std::cout << clapTrap1;
	std::cout << clapTrap2;
	std::cout << clapTrap3;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - SET VALUES]" << END << std::endl;
	clapTrap1.setAttackDamage(10);
	clapTrap2.setAttackDamage(2);
	clapTrap3.setName("CT3");
	clapTrap3.setEnergyPoints(0);
	std::cout << std::endl;
	std::cout << clapTrap1;
	std::cout << clapTrap2;
	std::cout << clapTrap3;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - BATTLE (ROUND 1)]" << END << std::endl;
	clapTrap1.attack("CT2");
	clapTrap2.takeDamage(10);
	clapTrap3.attack("CT2");
	std::cout << std::endl;
	std::cout << clapTrap1;
	std::cout << clapTrap2;
	std::cout << clapTrap3;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - BATTLE (ROUND 2)]" << END << std::endl;
	clapTrap1.beRepaired(5);
	clapTrap2.attack("CT3");
	clapTrap3.beRepaired(2);
	std::cout << std::endl;
	std::cout << clapTrap1;
	std::cout << clapTrap2;
	std::cout << clapTrap3;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - COPY]" << END << std::endl;
	ClapTrap	clapTrap4(clapTrap2);
	std::cout << clapTrap4;

	std::cout << std::endl;

	return (0);
}