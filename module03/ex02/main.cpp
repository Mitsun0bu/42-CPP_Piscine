/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:28:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/23 13:59:37 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	clapTrap1("CP1");
	FragTrap	fragTrap1("FT1");
	FragTrap	fragTrap2;
	FragTrap	fragTrap3(fragTrap2);

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - INITILIZATION]" << END << std::endl;
	std::cout << clapTrap1;
	std::cout << fragTrap1;
	std::cout << fragTrap2;
	std::cout << fragTrap3;


	std::cout << std::endl;

	std::cout << GREEN << "[TEST - SET VALUES]" << END << std::endl;
	clapTrap1.setAttackDamage(10);
	fragTrap1.setAttackDamage(2);
	fragTrap2.setName("FT2");
	std::cout << std::endl;
	std::cout << clapTrap1;
	std::cout << fragTrap1;
	std::cout << fragTrap2;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - BATTLE (ROUND 1)]" << END << std::endl;
	fragTrap1.attack("CP1");
	clapTrap1.takeDamage(2);
	fragTrap1.highFivesGuys();
	std::cout << std::endl;
	std::cout << clapTrap1;
	std::cout << fragTrap1;
	std::cout << fragTrap2;

	std::cout << std::endl;

	return (0);
}