/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:08:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/20 17:28:30 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	Thomas("Thomas", 42);
	Bureaucrat	Lucas("Lucas", 1);
	Bureaucrat	Manu("Manu", 150);
	Bureaucrat	Mitsu(Lucas);

	std::cout << std::endl;
	std::cout << GREEN << "[TEST - INITILIZATION]" << END << std::endl;
	std::cout << Thomas;
	std::cout << Lucas;
	std::cout << Manu;
	std::cout << Mitsu << std::endl;

	std::cout << GREEN << "[TEST - ALLOWED GRADE MODIFICATIONS]" << END << std::endl;
	try
	{
		Thomas.upGrade();
		Thomas.upGrade();
		Thomas.upGrade();
		Thomas.downGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - FORBIDDEN GRADE MODIFICATIONS]" << END << std::endl;
	try
	{
		Lucas.upGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Manu.downGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - FINAL BUREAUCRAT STATE]" << END << std::endl;
	std::cout << Thomas;
	std::cout << Lucas;
	std::cout << Manu << std::endl;

	return (0);
}