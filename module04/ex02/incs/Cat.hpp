/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:53:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/19 16:27:50 by llethuil         ###   ########lyon.fr   */
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

class Cat : public A_Animal
{
	public :

							Cat(void);
							Cat(Cat const &src);
		Cat					&operator=(Cat const &src);
		virtual std::string	getType(void) const;
		virtual void		makeSound(void) const;
		void				printIdea(int i_idea) const;
		void				setCatIdea(int i_idea, std::string text);
		virtual				~Cat(void);

	private :

		Brain	*_brain;
};
