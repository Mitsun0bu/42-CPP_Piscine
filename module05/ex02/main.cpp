/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:08:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/09/05 14:58:54 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "A_Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << std::endl;

	Bureaucrat				B1("Mitsunobu", 1);
	Bureaucrat				B2("Jacques Célert", 150);
	ShrubberyCreationForm	SCF1("MagicTree");
	ShrubberyCreationForm	SCF2(SCF1);
	RobotomyRequestForm		RRF1("Kelly Diot");
	ShrubberyCreationForm	RRF2(SCF1);
	PresidentialPardonForm	PPF1("Sylvie Bromasseur");
	ShrubberyCreationForm	PPF2(SCF1);

	std::cout << std::endl << GREEN << "[TEST - INITILIZATION]" << END;
	std::cout << std::endl << "===== BUREAUCRAT INFOS =====" << std::endl << std::endl;
	std::cout << B1;
	std::cout << std::endl;
	std::cout << B2;
	std::cout << std::endl;
	std::cout << std::endl << "===== FORMS INFOS =====" << std::endl << std::endl;
	std::cout << SCF1;
	std::cout << std::endl;
	std::cout << SCF2;
	std::cout << std::endl;
	std::cout << RRF1;
	std::cout << std::endl;
	std::cout << RRF2;
	std::cout << std::endl;
	std::cout << PPF1;
	std::cout << std::endl;
	std::cout << PPF2;
	std::cout << std::endl;


	std::cout << std::endl << GREEN << "[TEST - SHRUBBERRFY CREATION FORM]" << END << std::endl;
	B2.executeForm(SCF1);
	B1.executeForm(SCF1);
	B2.signForm(SCF1);
	B1.signForm(SCF1);
	B1.executeForm(SCF1);

	std::cout << std::endl;
	std::cout << GREEN << "[TEST - ROBOTOMY REQUEST FORM]" << END << std::endl << std::endl;
	B2.executeForm(RRF1);
	B1.executeForm(RRF1);
	B2.signForm(RRF1);
	B1.signForm(RRF1);
	B1.executeForm(RRF1);
	B1.executeForm(RRF1);
	B1.executeForm(RRF1);
	B1.executeForm(RRF1);

	std::cout << std::endl;
	std::cout << GREEN << "[TEST - PRESIDENTIAL PARDON FORM]" << END << std::endl << std::endl;
	B2.executeForm(PPF1);
	B1.executeForm(PPF1);
	B2.signForm(PPF1);
	B1.signForm(PPF1);
	B1.executeForm(PPF1);

	std::cout << std::endl;

	return (0);
}