/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:08:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/21 16:32:16 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "A_Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat				b1("Mitsunobu", 42);
	Bureaucrat				b2("Jacques Célert", 150);
	ShrubberyCreationForm	sC1("MagicTree");
	RobotomyRequestForm		rR1("Kelly Diot");

	std::cout << std::endl << GREEN << "[TEST - INITILIZATION]" << END << std::endl;
	std::cout << b1;
	std::cout << b2;
	std::cout << sC1;

	std::cout << std::endl << GREEN << "[TEST - SHRUBBERRY]" << END << std::endl;
	b2.executeForm(sC1);
	b1.executeForm(sC1);
	b2.signForm(sC1);
	b1.signForm(sC1);
	b1.executeForm(sC1);

	std::cout << std::endl;
	std::cout << GREEN << "[TEST - ROBOTOMY]" << END << std::endl;
	b2.executeForm(rR1);
	b1.executeForm(rR1);
	b2.signForm(rR1);
	b1.signForm(rR1);
	b1.executeForm(rR1);
	b1.executeForm(rR1);

	std::cout << std::endl;
	return (0);
}