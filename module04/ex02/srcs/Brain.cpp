/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:52:39 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 13:36:36 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

Brain::Brain(void)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A brain has been formed inside an animal's skull !" << std::endl;

	std::string n = "";

	for (int i = 0; i < 100; i++)
	{
		n = std::to_string(i);
		this->_ideas[i] = "Idea #" + n + ": ...";
	}
	return ;
}

Brain::Brain(Brain const & src)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A brain has been cloned !" << std::endl;

	*this = src;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

Brain&	Brain::operator=(Brain const & src)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src.getIdea(i);

	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

std::string	Brain::getIdea(int i_idea) const
{
	return (this->_ideas[i_idea]);
}

void	Brain::setIdea(int i_idea, std::string text)
{
	this->_ideas[i_idea] += text;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

Brain::~Brain(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "An animal's brain stopped working :(" << std::endl;

	return ;
}
