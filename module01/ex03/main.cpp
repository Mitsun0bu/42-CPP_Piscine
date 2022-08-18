/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lil@stud4student.42nyon.fr       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:35:44 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/18 11:02:35 by llethuil         ###   ########lyonlyo   */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

int main()
{
    Weapon  weapon1 = Weapon("Katana");
    HumanA  character1("Zoro", weapon1);

    character1.attack();
    weapon1.setType("Saber");
    character1.attack();
    std::cout << std::endl;

    Weapon  weapon2 = Weapon("Shurikens");
    HumanB  character2("Usopp");

    character2.setWeapon(weapon2);
    character2.attack();
    weapon2.setType("Nunchaku");
    character2.attack();
    std::cout << std::endl;

    return (0);
}