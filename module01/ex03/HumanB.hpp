/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:05:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/22 10:58:10 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "Weapon.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ CLASSES ~~~                               */
/*                                                                            */
/* ************************************************************************** */

class   HumanB
{
    public:
        /* constructor          */
                    HumanB(std::string name);
        /* member function      */
        void        setWeapon(Weapon &weapon);
        void        attack(void) const;
        /* destructor           */
                    ~HumanB(void);

    private:
        /* private attribute */
        std::string _name;
        Weapon      *_weapon;
};