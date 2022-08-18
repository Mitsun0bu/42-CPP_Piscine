/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:05:36 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/18 18:28:05 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

HumanB::HumanB(std::string name): _name(name)
{
    std::cout << BLUE << "[CONSTRUCTOR] : " << END
              << this->_name << " is ready to battle !"
              << std::endl;
    return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    return ;
}

void    HumanB::attack(void) const
{
    if (this->_weapon != NULL)
    {
        std::cout << this->_name
                  << " attacks with his "
                  << this->_weapon->getType()
                  << std::endl;
    }
    else
        std::cout << this->_name << " has no weapon ! " << std::endl;

    return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

HumanB::~HumanB(void)
{
    std::cout << PURPLE << "[DESTRUCTOR] : " << END
              << this->_name << " has left the battlefield !"
              << std::endl;
    return ;
}
