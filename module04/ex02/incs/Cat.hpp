/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:53:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 15:17:37 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP
# define CAT_HPP

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

		/* constructors											*/
						Cat(void);

		/* copy constructor										*/
						Cat(Cat const &src);

		/* operator overload									*/
		Cat&			operator=(Cat const &src);

		/* member functions										*/
		virtual void	makeSound(void) const;
		Brain&			getBrain(void) const;
		void			printIdea(int i_idea) const;
		void			setCatIdea(int i_idea, std::string text);

		/* destructor											*/
		virtual 		~Cat(void);

	private :

		/* private attributes									*/
		Brain*			_brain;
};

# endif
