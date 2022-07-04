/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:26:39 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/04 15:15:37 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie(void)
{
    static int  i = 0;

    this->_i = i;
    std::cout << "Zombie #" 
              << this->_i
              << " from the MegaHorde"
              << this->_name 
              << " has been created !" << std::endl;
    i ++;
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie #" 
              << this->_i
              << " has been killed !" << std::endl; 
    return ;
}

void    Zombie::announce(void) const
{
    std::cout << "Zombie #" 
              << this->_i
              << " : I want BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}

void    Zombie::set_name(std::string name)
{
    this->_name = name;
    return ;
}