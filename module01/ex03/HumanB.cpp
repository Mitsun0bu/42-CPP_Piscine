/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:05:36 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/06 11:13:53 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
    std::cout << this->_name
              << " is ready to battle !"
              << std::endl;
    return ;
}

HumanB::~HumanB(void)
{
    std::cout << this->_name
              << " has left the battlefield !"
              << std::endl;
    return ;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    return ;
}

void    HumanB::attack(void) const
{
    std::cout << this->_name
              << " attacks with his "
              << this->_weapon->getType()
              << std::endl;
    return ;
}