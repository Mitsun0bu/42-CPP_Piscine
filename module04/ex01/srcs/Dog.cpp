/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:01:04 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/19 15:06:19 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

Dog::Dog(void)
{
	std::cout << "The newborn animal is a dog !" << std::endl;
	this->_type = "dog";
	this->_brain = new Brain();
	return ;
}

Dog::Dog(Dog const &src)
{
	*this = src;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

Dog&	Dog::operator=(Dog const &src)
{
	this->_type = src.getType();
	// this->_brain = src.getBrain();
	*(this->_brain) = *(src._brain);
	return *this;
}

/* ************************************************************************** */
/*                                                                            */
/*                        ~~~ OTHER MEMBER FUNCTIONS ~~~                      */
/*                                                                            */
/* ************************************************************************** */

void	Dog::makeSound() const
{
	std::cout << "Dog : \"Woof.\"" << std::endl;
	return ;
}

Brain*	Dog::getBrain(void) const
{
	return (this->_brain);
}

void	Dog::printIdea(int i_idea) const
{
	std::cout << this->_brain->getIdea(i_idea) << std::endl;
	return ;
}

void	Dog::setDogIdea(int i_idea, std::string text)
{
	this->_brain->setIdea(i_idea, text);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

Dog::~Dog(void)
{
	std::cout << "A dog just died ..." << std::endl;
	delete this->_brain;
	return ;
}
