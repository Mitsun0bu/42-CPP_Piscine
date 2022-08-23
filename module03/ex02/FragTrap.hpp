/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:40:49 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/23 13:51:59 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

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

class FragTrap : public ClapTrap
{
	public:

		/* constructors									*/
					FragTrap(void);
					FragTrap(std::string name);

		/* copy constructor								*/
					FragTrap(FragTrap const & src);

		/* operator overload							*/
		FragTrap&	operator=(FragTrap const & src);

		/* member functions								*/
		std::string	getName(void) const;
		void		setName(std::string name);
		void		attack(std::string const & target);
		void		highFivesGuys(void);

		/* destructor									*/
					~FragTrap();
};

std::ostream&	operator<<(std::ostream & stream, FragTrap const & FragTrap);

# endif