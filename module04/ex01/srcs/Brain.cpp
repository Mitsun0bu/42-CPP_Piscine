/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:48:51 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/22 10:49:50 by llethuil         ###   ########lyon.fr   */
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
	std::string n = "";

	std::cout << "A brain has been formed inside an animal head !" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		n = std::to_string(i);
		this->_ideas[i] = "Idea #" + n + ": ...";
	}
	return ;
}

Brain::Brain(Brain const &src)
{
	*this = src;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

Brain&	Brain::operator=(Brain const &src)
{
	for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
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
	std::cout << "A brain stopped working inside an animal head !" << std::endl;
	return ;
}
