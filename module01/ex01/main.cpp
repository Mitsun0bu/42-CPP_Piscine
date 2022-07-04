/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:26:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/04 15:25:41 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <time.h>

# include "Zombie.hpp"

int main(void)
{
    srand (time(NULL));
    
    int	N = rand() % 10;

    Zombie *zombie_horde = zombieHorde(N, "MegaHorde");
    
    zombie_horde->announce();
    std::cout << std::endl;
    
    for (int i = 0; i < N; i ++)
        zombie_horde[i].announce();
    
    delete [] zombie_horde;
    
    return (0);
}