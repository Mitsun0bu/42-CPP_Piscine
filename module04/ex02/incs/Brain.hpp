/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:42:50 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 14:39:21 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef BRAIN_HPP
# define BRAIN_HPP

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

class Brain
{
	public :

		/* constructors										*/
						Brain(void);
		/* copy constructor									*/
						Brain(Brain const & src);

		/* operator overload								*/
		Brain&			operator=(Brain const & src);

		/* member functions									*/
		std::string		getIdea(int i_idea) const;
		void			setIdea(int i_idea, std::string text);

		/* destructor										*/
		virtual 		~Brain(void);

	protected :

		/* private attributes								*/
		std::string		_ideas[100];

};

# endif