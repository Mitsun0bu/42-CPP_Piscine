/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:43:01 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/23 15:29:51 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ CONSTRUCTORS ~~~                                  */
/*                                                                            */
/* ************************************************************************** */

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A FragTrap named " << this->_name
			  << " has spawned !" << std::endl;

	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A FragTrap named " << this->_name
			  << " has spawned !" << std::endl;

	this->_hitPoints = 100;
	this->_energyPoints = 500;
	this->_attackDamage = 30;

	return;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
			<< "A FragTrap named " << this->_name
			<< " has been duplicated !" << std::endl;

	*this = src;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ OPERATOR OVERLOAD ~~~                             */
/*                                                                            */
/* ************************************************************************** */

FragTrap&	FragTrap::operator=(FragTrap const &src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;

	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ OTHER MEMBER FUNCTIONS ~~~                        */
/*                                                                            */
/* ************************************************************************** */

std::string	FragTrap::getName(void) const
{
	return (this->_name);
}

void	FragTrap::setName(std::string name)
{
	this->_name = name;

	std::cout << "FragTrap is now named " << name << std::endl;

	return ;
}

void	FragTrap::attack(std::string const &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "FragTrap " << this->_name
				  << " is dead... Nothing happened..."
				  << std::endl;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << "FragTrap " << this->_name
				  << " tries to attack " << target << " ! "
				  << "But nothing happened..." << std::endl;
	}
	else
	{
		this->_energyPoints--;
		std::cout << "FragTrap " << this->_name
				  << " attacks " << target
				  << " causing " << this->_attackDamage
				  << " points of damage!" << std::endl;
	}

	return ;
}

void		FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << this->_name
			  << " is flexing and asking for a high five !"
			  << std::endl;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ DESTRUCTOR ~~~                                    */
/*                                                                            */
/* ************************************************************************** */

FragTrap::~FragTrap()
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "A FragTrap named " << this->_name
			  << " has been destroyed !" << std::endl;

	return ;

}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ NON-MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &stream, FragTrap const &FragTrap)
{
	stream << "The FragTrap named " << FragTrap.getName()
		   << " has :" << std::endl
		   << "\t- " << FragTrap.getHitPoints() << " hit points" << std::endl
		   << "\t- " << FragTrap.getEnergyPoints() << " energy points" << std::endl
		   << "\t- " << FragTrap.getAttackDamage() << " attack damage" << std::endl;

	return stream;
}