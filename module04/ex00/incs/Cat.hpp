/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:53:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 09:18:54 by llethuil         ###   ########lyon.fr   */
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

class Cat : public Animal
{
	public :

		/* constructors								*/
						Cat(void);

		/* copy constructor							*/
						Cat(Cat const &src);

		/* operator overload						*/
		Cat&			operator=(Cat const &src);

		/* member functions							*/
		virtual void	makeSound(void) const;

		/* destructor								*/
		virtual 		~Cat(void);
};

# endif
