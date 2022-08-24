/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:49:30 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 14:50:27 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

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

class A_Animal
{
	public :

		/* constructors										*/
							A_Animal(void);

		/* copy constructor									*/
							A_Animal(A_Animal const & src);

		/* operator overload								*/
		A_Animal&			operator=(A_Animal const & src);

		/* member functions									*/
		std::string			getType(void) const;
		virtual void		makeSound(void) const = 0;

		/* destructor										*/
		virtual 			~A_Animal(void);

	protected:

		/* private attributes								*/
		std::string			_type;
};

# endif