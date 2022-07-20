/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:17:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/20 16:15:11 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ CLASSES ~~~                               */
/*                                                                            */
/* ************************************************************************** */

class ScavTrap : virtual public ClapTrap
{
	public:

		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &src);
		ScavTrap			&operator=(ScavTrap const &src);
		std::string			get_name(void) const;
		void				set_name(std::string name);
		void				attack(std::string const &target);
		void				guardGate(void);
		static const int	EP = 50;
		~ScavTrap();

};

std::ostream	&operator<<(std::ostream &stream, ScavTrap const &ScavTrap);
