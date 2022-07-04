/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:26:30 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/04 12:31:36 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie  *newZombie(std::string name)
{
    Zombie  *heap_zombie = new Zombie(name);

    return (heap_zombie);
}
