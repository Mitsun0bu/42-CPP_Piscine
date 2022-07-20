/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:08:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/20 12:09:28 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"
# include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	Mitsunobu("Mitsunobu", 42);
	Form		Contract_1("Contract", 10, 50);
	Form		Contract_2("Contract", 67, 50);

	/* TEST INITILIZATION AND << OVERLOAD */
	std::cout << std::endl;
	std::cout << Mitsunobu;

	Mitsunobu.signForm(Contract_1);

	/* FINAL BUREAUCRAT STATE */
	std::cout << std::endl;
	std::cout << Mitsunobu;

	std::cout << std::endl;
	return (0);
}