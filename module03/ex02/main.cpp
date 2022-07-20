/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:28:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/20 16:03:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	clap_trap_1("CP1");
	FragTrap	frag_trap_1("FT1");
	FragTrap	frag_trap_2;
	FragTrap	frag_trap_3(frag_trap_2);

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - INITILIZATION]" << END << std::endl;
	std::cout << clap_trap_1;
	std::cout << frag_trap_1;
	std::cout << frag_trap_2;
	std::cout << frag_trap_3;


	std::cout << std::endl;

	std::cout << GREEN << "[TEST - SET VALUES]" << END << std::endl;
	clap_trap_1.set_ad(10);
	frag_trap_1.set_ad(2);
	frag_trap_2.set_name("FT2");
	std::cout << std::endl;
	std::cout << clap_trap_1;
	std::cout << frag_trap_1;
	std::cout << frag_trap_2;

	std::cout << std::endl;

		std::cout << GREEN << "[TEST - BATTLE (ROUND 1)]" << END << std::endl;
	frag_trap_1.attack("CP1");
	clap_trap_1.takeDamage(2);
	frag_trap_2.highFivesGuys();
	std::cout << std::endl;
	std::cout << clap_trap_1;
	std::cout << frag_trap_1;
	std::cout << frag_trap_2;

	std::cout << std::endl;

	return (0);
}