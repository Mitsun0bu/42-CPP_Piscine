/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:08:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/21 11:12:11 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

void	print_state(Bureaucrat &Thomas, Bureaucrat &Lucas, Bureaucrat &Manu);
void	allowed_grade_modif(Bureaucrat &Thomas);
void	forbidden_grade_modif(Bureaucrat &Lucas, Bureaucrat &Manu);

int	main(void)
{
	Bureaucrat	Thomas("Thomas", 42);
	Bureaucrat	Lucas("Lucas", 1);
	Bureaucrat	Manu("Manu", 150);

	std::cout << std::endl << GREEN << "[TEST - BUREAUCRAT INIT STATE]" << END << std::endl;
	print_state(Thomas, Lucas, Manu);

	std::cout << GREEN << "[TEST - ALLOWED GRADE MODIFICATIONS]" << END << std::endl;
	allowed_grade_modif(Thomas);

	std::cout << std::endl << GREEN << "[TEST - FORBIDDEN GRADE MODIFICATIONS]" << END << std::endl;
	forbidden_grade_modif(Lucas, Manu);

	std::cout << std::endl << GREEN << "[TEST - BUREAUCRAT FINAL STATE]" << END << std::endl;
	print_state(Thomas, Lucas, Manu);

	return (0);
}

void	print_state(Bureaucrat &Thomas, Bureaucrat &Lucas, Bureaucrat &Manu)
{
	std::cout << Thomas;
	std::cout << Lucas;
	std::cout << Manu << std::endl;
	return ;
}

void	allowed_grade_modif(Bureaucrat &Thomas)
{
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
	return ;
}

void	forbidden_grade_modif(Bureaucrat &Lucas, Bureaucrat &Manu)
{
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
	return ;
}