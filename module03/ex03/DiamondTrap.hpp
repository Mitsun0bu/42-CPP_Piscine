/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:05:42 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/23 15:37:49 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

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

		/* constructors									*/
						DiamondTrap(void);
						DiamondTrap(std::string name);

		/* copy constructor								*/
						DiamondTrap(DiamondTrap const &src);

		/* operator overload							*/
		DiamondTrap&	operator=(DiamondTrap const &src);

		/* member functions								*/
		std::string		getName(void) const;
		void			setName(std::string name);
		void			attack(std::string const &target);
		void			whoAmI(void) const;

		/* destructor									*/
						~DiamondTrap();

	private :

		/* private attributes							*/
		std::string		_name;
};

std::ostream	&operator<<(std::ostream &stream, DiamondTrap const &DiamondTrap);

# endif