/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:39:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/22 11:15:04 by llethuil         ###   ########lyon.fr   */
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
    this->_lvl_tab[0] = "DEBUG";
	this->_lvl_tab[1] = "INFO";
	this->_lvl_tab[2] = "WARNING";
	this->_lvl_tab[3] = "ERROR";

	this->_func_ptr_tab[0] = &Harl::_debug;
	this->_func_ptr_tab[1] = &Harl::_info;
	this->_func_ptr_tab[2] = &Harl::_warning;
	this->_func_ptr_tab[3] = &Harl::_error;

    std::cout << "Harl has been created !" << std::endl;
    return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

void    Harl::complain(std::string level)
{

    for (int i = 0; i < 4; i ++)
    {
        if (this->_lvl_tab[i] == level)
        {
            (void)(this->*_func_ptr_tab[i])();
            return ;
        }
    }
    return ;
}

void    Harl::_debug(void)
{
    std::cout << "I love having extra bacon for my burger. "
              << "I really do!" << std::endl;
    return ;
}

void    Harl::_info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. "
              << "You didn’t put enough bacon in my burger! "
              << "If you did, I wouldn’t be asking for more!" << std::endl;
    return ;
}

void    Harl::_warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. "
              << "I’ve been coming for years "
              << "whereas you started working here since last month." << std::endl;
    return ;
}

void    Harl::_error(void)
{
    std::cout << "This is unacceptable! "
              << "I want to speak to the manager now." << std::endl;
    return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

Harl::~Harl(void)
{
    std::cout << "Harl has been destroyed !" << std::endl;
    return ;
}
