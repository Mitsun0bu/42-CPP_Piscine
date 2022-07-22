/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:26:24 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/22 11:06:02 by llethuil         ###   ########lyon.fr   */
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

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ CLASSES ~~~                               */
/*                                                                            */
/* ************************************************************************** */

class   Weapon
{
    public:
        /* constructors          */
                            Weapon(void);
                            Weapon(std::string type);
        /* member functions      */
        std::string const   &getType(void);
        void                setType(std::string new_type);
        /* destructor           */
                            ~Weapon(void);

    private:
        /* private attribute */
        std::string         _type;
};
