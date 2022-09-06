/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:08:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/09/05 15:40:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "A_Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int	main(void)
{
	std::cout << std::endl;

	Bureaucrat	B1("Harry Stote", 1);
	Intern		someRandomIntern;
	A_Form*		randomForm;
	A_Form*		robotomyRequestForm;

	std::cout << std::endl << GREEN << "[TEST - INALID FORM NAME]" << END << std::endl;
	randomForm = someRandomIntern.makeForm("random form :)", "Bender");

	std::cout << std::endl << GREEN << "[TEST - VALID FORM NAME]" << END << std::endl;

	robotomyRequestForm = someRandomIntern.makeForm("Robotomy Request", "Bender");
	if(!robotomyRequestForm)
		return (0);
	A_Form&		formRef = *robotomyRequestForm;
	B1.signForm(formRef);
	B1.executeForm(formRef);

	std::cout << std::endl;

	delete robotomyRequestForm;

	return (0);
}
