/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:17:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/23 14:39:47 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

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

		/* constructors										*/
							ScavTrap(void);
							ScavTrap(std::string name);

		/* copy constructor									*/
							ScavTrap(ScavTrap const & src);

		/* operator overload								*/
		ScavTrap&			operator=(ScavTrap const & src);

		/* member functions									*/
		std::string			getName(void) const;
		void				setName(std::string name);
		void				attack(std::string const & target);
		void				guardGate(void);
		static const int	EP = 50;

		/* destructor									*/
							~ScavTrap();

};

std::ostream	&operator<<(std::ostream &stream, ScavTrap const &ScavTrap);

# endif