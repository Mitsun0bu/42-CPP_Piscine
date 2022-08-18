/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:35:44 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/18 11:37:34 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

int main()
{
    Weapon  weapon1 = Weapon("katana");
    HumanA  character1("Zoro", weapon1);

    std::cout << std::endl;
    character1.attack();
    weapon1.setType("saber", "Zoro");
    character1.attack();
    std::cout << std::endl;

    Weapon  weapon2 = Weapon("shuriken");
    HumanB  character2("Usopp");

    std::cout << std::endl;
    character2.setWeapon(weapon2);
    character2.attack();
    weapon2.setType("nunchaku", "Usopp");
    character2.attack();
    std::cout << std::endl;

    return (0);
}