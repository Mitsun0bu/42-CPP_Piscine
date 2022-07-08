/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:26:41 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/07 11:02:58 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <time.h>

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ CLASSES ~~~                               */
/*                                                                            */
/* ************************************************************************** */

class Zombie
{
     public:

        Zombie(void);
        void        announce(void) const;
        void        set_name(std::string);
        ~Zombie(void);
      
    private:

        int 	    _i;
        std::string _name;
};

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

Zombie* zombieHorde(int N, std::string name);