/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:01:04 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 14:50:12 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

Dog::Dog(void) : _brain(new Brain())
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "The newborn animal is a dog !" << std::endl;

	this->_type = "dog";

	return ;
}

Dog::Dog(Dog const & src) : _brain(new Brain())
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
			  << "An dog has been duplicated !" << std::endl;

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
	*(this->_brain) = src.getBrain();

	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

// std::string	Dog::getType(void) const
// {
// 	return (this->_type);
// }

void	Dog::makeSound() const
{
	std::cout << "Dog : \"Woof.\"" << std::endl;

	return ;
}

Brain&	Dog::getBrain(void) const
{
	return (*(this->_brain));
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
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "A dog just died ..." << std::endl;

	delete this->_brain;

	return ;
}
