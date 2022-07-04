/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:26:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/04 12:54:53 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <time.h>

# include "Zombie.hpp"

int main(void)
{
    srand (time(NULL));
    
    std::string name_list[4] = { "Rick", "Darryl", "Sarah", "Michonne" };
    std::string name_1;
    std::string name_2;
    
    name_1 = name_list[rand() % 4] + " from Stack City";
    name_2 = name_list[rand() % 4] + " from Heap City";

    randomChump(name_1);

    Zombie *heap_zombie = newZombie(name_2);
    heap_zombie->announce();
    delete heap_zombie;
    
    return (0);
}