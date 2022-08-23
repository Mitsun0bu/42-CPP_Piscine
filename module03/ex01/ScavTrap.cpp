/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:20:31 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/23 12:00:13 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ CONSTRUCTORS ~~~                                  */
/*                                                                            */
/* ************************************************************************** */

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A ScavTrap named " << this->_name
			  << " has spawned !" << std::endl;

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A ScavTrap named " << this->_name
			  << " has spawned !" << std::endl;

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	return;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
			  << "A ScavTrap named " << this->_name
			  << " has been duplicated !" << std::endl;

	*this = src;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ OPERATOR OVERLOAD ~~~                             */
/*                                                                            */
/* ************************************************************************** */

ScavTrap	&ScavTrap::operator=(ScavTrap const &src)
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

std::string	ScavTrap::getName(void) const
{
	return (this->_name);
}

void	ScavTrap::setName(std::string name)
{
	this->_name = name;
	std::cout << "ScavTrap is now named " << name << std::endl;

	return ;
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name
				  << " is dead... Nothing happened..."
				  << std::endl;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name
				  << " tries to attack " << target << " ! "
				  << "But nothing happened..." << std::endl;
	}
	else
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name
				  << " attacks " << target
				  << " causing " << this->_attackDamage
				  << " points of damage!" << std::endl;
	}

	return ;
}

void		ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name
			<< " has entered the \"Gate Keeper\" mode."
			<< " He's now keeping the Unknown Dungeon gate."
			<< std::endl;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ DESTRUCTOR ~~~                                    */
/*                                                                            */
/* ************************************************************************** */

ScavTrap::~ScavTrap()
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "A ScavTrap named " << this->_name
			  << " has been destroyed !" << std::endl;
	return ;

}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ NON-MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &stream, ScavTrap const &ScavTrap)
{
	stream << "The ScavTrap named " << ScavTrap.getName()
		   << " has :" << std::endl
		   << "\t- " << ScavTrap.getHitPoints() << " hit points" << std::endl
		   << "\t- " << ScavTrap.getEnergyPoints() << " energy points" << std::endl
		   << "\t- " << ScavTrap.getAttackDamage() << " attack damage" << std::endl;

	return stream;
}