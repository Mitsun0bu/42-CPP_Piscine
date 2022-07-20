/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:55:16 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/20 15:47:44 by llethuil         ###   ########lyon.fr   */
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
/*                            ~~~ COLOR DEFINES ~~~                           */
/*                                                                            */
/* ************************************************************************** */

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define END "\033[0m"

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ CLASSES ~~~                               */
/*                                                                            */
/* ************************************************************************** */

class ClapTrap
{
	public :

		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		ClapTrap	&operator=(ClapTrap const &src);
		std::string	get_name(void) const;
		int			get_hp(void) const;
		int			get_ep(void) const;
		int			get_ad(void) const;
		void		set_name(std::string name);
		void		set_hp(int hp);
		void		set_ep(int ep);
		void		set_ad(int ad);
		void		attack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		~ClapTrap();

	protected:

		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
};

std::ostream	&operator<<(std::ostream &stream, ClapTrap const &ClapTrap);