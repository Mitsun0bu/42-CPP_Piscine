/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:08:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/10 10:58:38 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

void	printState(Bureaucrat &B1, Bureaucrat &B2, Bureaucrat &B3, std::string state);
void	allowedGradeModification(Bureaucrat &B);
void	copyBureaucrat(Bureaucrat &B);
void	forbiddenGradeModification(Bureaucrat &B1, Bureaucrat &B2);

int	main(void)
{
	Bureaucrat	Thomas("Thomas", 42);
	Bureaucrat	Lucas("Lucas", 1);
	Bureaucrat	Manu("Manu", 150);

	printState(Thomas, Lucas, Manu, "init");

	allowedGradeModification(Thomas);

	forbiddenGradeModification(Lucas, Manu);

	copyBureaucrat(Lucas);

	printState(Thomas, Lucas, Manu, "final");

	return (0);
}

void	printState(Bureaucrat &B1, Bureaucrat &B2, Bureaucrat &B3, std::string state)
{
	if (state == "init")
		std::cout << std::endl << GREEN << "[TEST - BUREAUCRAT INIT STATE]" << END << std::endl;
	else if (state == "final")
		std::cout << std::endl << GREEN << "[TEST - BUREAUCRAT FINAL STATE]" << END << std::endl;

	std::cout << B1;
	std::cout << B2;
	std::cout << B3 << std::endl;

	return ;
}

void	allowedGradeModification(Bureaucrat &B)
{
	std::cout << GREEN << "[TEST - ALLOWED GRADE MODIFICATIONS]" << END << std::endl;

	try
	{
		B.upGrade();
		B.upGrade();
		B.upGrade();
		B.downGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return ;
}

void	forbiddenGradeModification(Bureaucrat &B1, Bureaucrat &B2)
{
	std::cout << std::endl << GREEN << "[TEST - FORBIDDEN GRADE MODIFICATIONS]" << END << std::endl;

	try
	{
		B1.upGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		B2.downGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return ;
}

void	copyBureaucrat(Bureaucrat &B)
{
	std::cout << std::endl << GREEN << "[TEST - BUREAUCRAT COPY]" << END << std::endl;

	Bureaucrat	copyLucas(B);

	std::cout << copyLucas;

	return ;
}