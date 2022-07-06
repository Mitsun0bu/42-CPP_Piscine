/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:35:44 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/06 11:13:36 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

int main()
{
    Weapon club_1 = Weapon("Katana");
    HumanA bob("Zoro", club_1);
    bob.attack();
    club_1.setType("Saber");
    bob.attack();

    std::cout << std::endl;
    
    Weapon club_2 = Weapon("Shurikens");
    HumanB jim("Usop");
    jim.setWeapon(club_2);
    jim.attack();
    club_2.setType("Nunchaku");
    jim.attack();
    std::cout << std::endl;
    
    return (0);
}