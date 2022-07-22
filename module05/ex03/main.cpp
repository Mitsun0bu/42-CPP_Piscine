/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:08:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/22 17:40:04 by llethuil         ###   ########lyon.fr   */
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
	Bureaucrat	b1("Harry Stote", 1);
	Intern		someRandomIntern;
	A_Form*		randomForm;
	A_Form*		robotomyRequestForm;

	std::cout << std::endl << GREEN << "[TEST - INALID FORM NAME]" << END << std::endl;
	randomForm = someRandomIntern.makeForm("random form :)", "Bender");

	std::cout << std::endl << GREEN << "[TEST - VALID FORM NAME]" << END << std::endl;
	robotomyRequestForm = someRandomIntern.makeForm("Robotomy Request", "Bender");
	A_Form&		formRef = *robotomyRequestForm;
	b1.signForm(formRef);
	b1.executeForm(formRef);


	std::cout << std::endl;

	delete robotomyRequestForm;

	return (0);
}
