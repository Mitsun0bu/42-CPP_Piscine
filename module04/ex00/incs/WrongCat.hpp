/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:00:17 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 10:34:44 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                             ~~~ CLASSES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

class WrongCat : public WrongAnimal
{
	public :

		/* constructors									*/
						WrongCat(void);

		/* copy constructor								*/
						WrongCat(WrongCat const & src);

		/* operator overload							*/
		WrongCat&		operator=(WrongCat const & src);

		/* member functions								*/
		void			makeSound(void) const;

		/* destructor									*/
						~WrongCat(void);
};

# endif
