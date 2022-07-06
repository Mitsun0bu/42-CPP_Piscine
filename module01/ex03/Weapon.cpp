/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:25:53 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/06 10:51:57 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(void)
{
    std::cout << "An unknown type weapon has been created !" 
              << std::endl;
    return;
}

Weapon::Weapon(std::string type): _type(type)
{
    std::cout << "A weapon of type "
              << this->_type
              << " has been created !"
              << std::endl;
    return;
}

Weapon::~Weapon()
{
    std::cout << "A weapon has been destroyed !" << std::endl;
    return;
}

std::string const &Weapon::getType(void)
{
    return (this->_type);
}

void        Weapon::setType(std::string new_type)
{
    this->_type = new_type;
    return ;
}
