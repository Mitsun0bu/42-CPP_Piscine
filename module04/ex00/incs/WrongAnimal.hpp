/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:53:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 10:23:05 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

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

class WrongAnimal
{
	public :

		/* constructors										*/
						WrongAnimal(void);

		/* copy constructor									*/
						WrongAnimal(WrongAnimal const &src);

		/* operator overload								*/
		WrongAnimal&	operator=(WrongAnimal const &src);

		/* member functions									*/
		std::string		getType(void) const;
		void			makeSound(void) const;

		/* destructor										*/
						~WrongAnimal(void);

	protected:

		/* private attributes								*/
		std::string		_type;
};

# endif