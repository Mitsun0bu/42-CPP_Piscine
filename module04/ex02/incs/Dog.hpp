/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:56:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 15:17:47 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef DOG_HPP
# define DOG_HPP

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

class Dog : public A_Animal
{
	public :

		/* constructors											*/
						Dog(void);

		/* copy constructor										*/
						Dog(Dog const &src);

		/* operator overload									*/
		Dog&			operator=(Dog const &src);

		/* member functions										*/
		virtual void	makeSound(void) const;
		Brain&			getBrain(void) const;
		void			printIdea(int i_idea) const;
		void			setDogIdea(int i_idea, std::string text);

		/* destructor											*/
		virtual			~Dog(void);

	private :

		/* private attributes									*/
		Brain*			_brain;
};

# endif