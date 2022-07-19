/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:56:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/19 15:05:36 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

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

class Dog : public Animal
{
	public :

						Dog(void);
						Dog(Dog const &src);
		Dog				&operator=(Dog const &src);
		virtual void	makeSound(void) const;
		Brain			*getBrain(void) const;
		void			printIdea(int i_idea) const;
		void			setDogIdea(int i_idea, std::string text);
		virtual 		~Dog(void);

	private :

		Brain	*_brain;
};
