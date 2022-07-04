/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:34:05 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/04 15:24:45 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie*    zombieHorde(int N, std::string name)
{
    Zombie  *zombie_horde = new Zombie[N];

    for (int i = 0; i < N; i++)
        zombie_horde[i].set_name(name);

    return (zombie_horde);
}