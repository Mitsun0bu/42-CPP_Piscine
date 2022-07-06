/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:04:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/06 11:28:05 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(&weapon)
{
    std::cout << this->_name
              << " is ready to battle !"
              << std::endl;
    return ;
}

HumanA::~HumanA(void)
{
    std::cout << this->_name
              << " has left the battlefield !"
              << std::endl;
    return ;
}

void    HumanA::attack(void)
{
    std::cout << this->_name
              << " attacks with his "
              << this->_weapon->getType()
              << std::endl;
    return ;
}
