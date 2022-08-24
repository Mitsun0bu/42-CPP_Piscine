/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:23:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 09:21:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef ANIMAL_HPP
# define ANIMAL_HPP

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

class Animal
{
	public :

		/* constructors									*/
						Animal(void);

		/* copy constructor								*/
						Animal(Animal const & src);

		/* operator overload							*/
		Animal&			operator=(Animal const & src);

		/* member functions								*/
		std::string		getType(void) const;
		virtual void	makeSound(void) const;

		/* destructor									*/
		virtual 		~Animal(void);

	protected:

		/* private attributes							*/
		std::string		_type;
};

# endif