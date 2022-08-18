/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:39:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/18 16:49:23 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

Harl::Harl(void)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "Harl has been created !" << std::endl;

	this->_lvlTable[0] = "DEBUG";
	this->_lvlTable[1] = "INFO";
	this->_lvlTable[2] = "WARNING";
	this->_lvlTable[3] = "ERROR";

	this->_funcPtrTab[0] = &Harl::_debug;
	this->_funcPtrTab[1] = &Harl::_info;
	this->_funcPtrTab[2] = &Harl::_warning;
	this->_funcPtrTab[3] = &Harl::_error;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i ++)
	{
		if (this->_lvlTable[i] == level)
		{
			(void)(this->*_funcPtrTab[i])();
			return ;
		}
	}
	return ;
}

void	Harl::_debug(void)
{
	std::cout << GREEN << "[DEBUG]\t\t" << END
			  << "Harl 2.0 : "
			  << "I hate debugging, it's boring..."
			  << std::endl;
	return ;
}

void	Harl::_info(void)
{
	std::cout << GREEN << "[INFO]\t\t" << END
			  << "Harl 2.0 : "
			  << "Come on, you don't need any infos, I am the one doing the job..."
			  << std::endl;
	return ;
}

void	Harl::_warning(void)
{
	std::cout << GREEN << "[WARNING]\t" << END
			  << "Harl 2.0 : "
			  << "I'm warning you, if you continue doing bullshit we'll both be in danger !"
			  << std::endl;
	return ;
}

void	Harl::_error(void)
{
	std::cout << GREEN << "[ERROR]\t\t" << END
			  << "Harl 2.0 : "
			  << "I told you to stop your %@$#* !!! "
			  << std::endl;
	std::cout << "\t\t*** LOUD EXPLOSION NOISE ***" << std::endl;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

Harl::~Harl(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "Harl has been destroyed !" << std::endl;
	return ;
}
