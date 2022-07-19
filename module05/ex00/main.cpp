/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:08:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/19 18:33:28 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	Thomas("Thomas", 42);
	Bureaucrat	Lucas("Lucas", 1);
	Bureaucrat	Manu("Manu", 150);

	/* TEST INITILIZATION AND << OVERLOAD */
	std::cout << std::endl;
	std::cout << Thomas;
	std::cout << Lucas;
	std::cout << Manu << std::endl;

	/* TEST ALLOWED GRADE MODIFICATIONS */
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
	/* TEST FORBIDDEN GRADE MODIFICATIONS */
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

	/* FINAL BUREAUCRAT STATE */
	std::cout << std::endl;
	std::cout << Thomas;
	std::cout << Lucas;
	std::cout << Manu << std::endl;

	return (0);
}