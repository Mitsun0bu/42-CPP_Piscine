/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:05:42 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/13 18:35:12 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ CLASSES ~~~                               */
/*                                                                            */
/* ************************************************************************** */

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:

		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &src);
		DiamondTrap	&operator=(DiamondTrap const &src);
		std::string	get_name(void) const;
		void		set_name(std::string name);
		void		attack(std::string const &target);
		void		whoAmI(void) const;
		~DiamondTrap();

	private :

		std::string	_name;
		std::string	_inherited_name;
};

std::ostream	&operator<<(std::ostream &stream, DiamondTrap const &DiamondTrap);