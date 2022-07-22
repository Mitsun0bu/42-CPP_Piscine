/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:27:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/22 10:49:50 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	A_Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A ShrubberyCreationForm has been created by the secretary." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	A_Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
				  << "The newly created form is a ShrubberyCreationForm." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
	A_Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
			<< "A ShrubberyCreationForm named " << src.getName()
			<< " has been duplicated !" << std::endl;
	*this = src;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

ShrubberyCreationForm&		ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	this->_target = src._target;
	return (*this);
}

std::ostream&	operator<<(std::ostream &stream, ShrubberyCreationForm const &ShrubberyCreationForm)
{
	std::string	signedMsg = "";
	if (ShrubberyCreationForm.getSignState() == true)
		signedMsg = "Yes";
	else
		signedMsg = "No";
	stream << "===== SHRUBBERRY FORM INFOS =====" << std::endl
		   << "Name : " << ShrubberyCreationForm.getName() << std::endl
		   << "Signed : " << signedMsg << std::endl
		   << "Grade required to sign : " << ShrubberyCreationForm.getSignGrade() << std::endl
		   << "Grade required to execute : " << ShrubberyCreationForm.getExecGrade() << std::endl;
	return stream;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

void				ShrubberyCreationForm::doFormJob(void) const
{
	std::ofstream outfile(this->_target + "_shrubbery");

	outfile << "\t\t\t\t\t\t  _{\\ _{\\{\\/}/}/}__" << std::endl
			<< "\t\t\t\t\t\t {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl
	<< "\t\t\t\t\t\t{/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl
	<< "\t\t\t\t\t {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl
	<< "\t\t\t\t\t{/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl
	<< "\t\t\t\t   _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl
	<< "\t\t\t\t  {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl
	<< "\t\t\t\t  _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl
	<< "\t\t\t\t {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl
	<< "\t\t\t \t  {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl
	<< "\t\t\t \t   {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl
	<< "\t\t\t\t  {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl
	<< "\t\t\t\t   {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl
	<< "\t\t\t\t\t {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl
	<< "\t\t\t\t\t  (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl
	<< "\t\t\t \t\t   {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl
	<< "\t\t\t\t\t\t{/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl
	<< "\t\t\t \t\t\t {){/ {\\/}{\\/} \\}\\}" << std::endl
	<< "\t\t\t\t\t\t (_)  \\.-'.-/" << std::endl
	<< "\t\t\t         __...--- |'-.-'| --...__" << std::endl
	<< "\t\t\t  _...--\"   .-'   |'-.-'|  ' -.  ""--..__" << std::endl
	<< "\t\t\t-\"    ' .  . '    |.'-._| '  . .  '   .__" << std::endl
	<< "\t\t\t.  '-  '    .--'  | '-.'|    .  '  . '" << std::endl
	<< "\t\t\t         ' ..     |'-_.-|" << std::endl
	<< "\t\t\t .  '  .       _.-|-._ -|-._  .  '  ." << std::endl
	<< "\t\t\t             .'   |'- .-|   '." << std::endl
	<< "\t\t\t ..-'   ' .  '.   `-._.-�   .'  '  - ." << std::endl
	<< "\t\t\t  .-' '        '-._______.-'     '  ." << std::endl
	<< "\t\t\t       .      ~," << std::endl
	<< "\t\t\t   .       .   |\\   .    ' '-." << std::endl
	<< "\t\t\t   ___________/  \\____________" << std::endl
	<< "\t\t\t  /  Why is it, when you want \\" << std::endl
	<< "\t\t\t  |  something, it is so damn   |" << std::endl
	<< "\t\t\t  |    much work to get it?     |" << std::endl
	<< "\t\t\t   \\___________________________/" << std::endl;

	outfile.close();
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "The ShrubberyCreationForm can be archived." << std::endl;
	return ;
}
