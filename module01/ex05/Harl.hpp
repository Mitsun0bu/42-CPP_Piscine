/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:35:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/22 13:30:32 by llethuil         ###   ########lyon.fr   */
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

class   Harl
{
    public:
        /* constructor          */
                    Harl(void);
        /* member function      */
        void        complain(std::string level);
        /* destructor           */
                    ~Harl(void);

    private:
        /* private attributes */
        void        _debug(void);
        void        _info(void);
        void        _warning(void);
        void        _error(void);
        std::string _lvl_tab[4];
		void        (Harl::*_func_ptr_tab[4])(void);
};
