/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:56:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/19 16:27:44 by llethuil         ###   ########lyon.fr   */
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

class Dog : public A_Animal
{
	public :

							Dog(void);
							Dog(Dog const &src);
		Dog					&operator=(Dog const &src);
		virtual std::string	getType(void) const;
		virtual void		makeSound(void) const;
		void				printIdea(int i_idea) const;
		void				setDogIdea(int i_idea, std::string text);
		virtual 			~Dog(void);

	private :

		Brain	*_brain;
};
