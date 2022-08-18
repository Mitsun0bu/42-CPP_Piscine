/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:26:24 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/18 10:50:29 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEAPON_HPP
# define WEAPON_HPP

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
        std::string const & getType(void);
        void                setType(std::string new_type);

        /* destructor           */
                            ~Weapon(void);

    private:

        /* private attribute */
        std::string         _type;
};

# endif
