/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:08:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/10 11:18:21 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"
# include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << std::endl;

	Bureaucrat	Mitsunobu("Mitsunobu", 42);
	Form		Contract_1("Contract_1", 10, 50);
	Form		copyContract_1(Contract_1);
	Form		Contract_2("Contract_2", 67, 50);

	std::cout << std::endl;
	std::cout << GREEN << "[TEST - INITILIZATION]" << END << std::endl;
	std::cout << Mitsunobu;

	std::cout << std::endl;
	std::cout << GREEN << "[TEST - COPY FORM]" << END << std::endl;
	std::cout << copyContract_1 << std::endl;

	std::cout << std::endl;
	std::cout << GREEN << "[TEST - SIGNFORM METHOD]" << END << std::endl;
	Mitsunobu.signForm(Contract_1);
	Mitsunobu.signForm(Contract_2);



	std::cout << std::endl;
	return (0);
}