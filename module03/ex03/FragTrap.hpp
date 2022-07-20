/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:41:41 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/20 16:15:24 by llethuil         ###   ########lyon.fr   */
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

class FragTrap : virtual public ClapTrap
{
	public:

		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &src);
		FragTrap			&operator=(FragTrap const &src);
		std::string			get_name(void) const;
		void				set_name(std::string name);
		void				attack(std::string const &target);
		void				highFivesGuys(void) const;
		static const int	HP = 100;
		static const int	AD = 30;
		~FragTrap();
};

std::ostream	&operator<<(std::ostream &stream, FragTrap const &FragTrap);
