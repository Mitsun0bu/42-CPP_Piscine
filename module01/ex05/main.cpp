/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:49:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/19 09:46:36 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main(void)
{
	Harl	Harl_2_0;

	/* Test existing levels */
	std::cout << std::endl;
	Harl_2_0.complain("DEBUG");
	Harl_2_0.complain("INFO");
	Harl_2_0.complain("WARNING");
	Harl_2_0.complain("ERROR");
	std::cout << std::endl;

	/* Test with a non-existing level */
	Harl_2_0.complain("TROLL");

	return (0);
}