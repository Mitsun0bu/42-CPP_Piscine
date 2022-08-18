/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:04:32 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/18 10:57:24 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMANA_HPP
# define HUMANA_HPP

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

class   HumanA
{
    public:

        /* constructor                                          */
                    HumanA(std::string name, Weapon& weapon);

        /* member function                                      */
        void        attack(void) const;

        /* destructor                                           */
                    ~HumanA(void);

    private:

        /* private attributes                                   */
        std::string _name;
        Weapon&     _weapon;
};

# endif