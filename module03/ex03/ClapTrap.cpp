/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:21:54 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/23 11:53:10 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ CONSTRUCTORS ~~~                                  */
/*                                                                            */
/* ************************************************************************** */

ClapTrap::ClapTrap(void) : _name("---"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			<< "A ClapTrap named " << this->_name
			<< " has spawned !" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			<< "A ClapTrap named " << this->_name
			<< " has spawned !" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
			  << "A ClapTrap named " << this->_name
			  << " has been duplicated !" << std::endl;
	*this = src;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ OPERATOR OVERLOAD ~~~                             */
/*                                                                            */
/* ************************************************************************** */

ClapTrap	&ClapTrap::operator=(ClapTrap const &src)
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

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
	std::cout << "ClapTrap is now named " << name << std::endl;
	return ;
}

void	ClapTrap::setHitPoints(int hp)
{
	this->_hitPoints = hp;
	return ;
}

void	ClapTrap::setEnergyPoints(int ep)
{
	this->_energyPoints = ep;
	return ;
}

void	ClapTrap::setAttackDamage(int ad)
{
	this->_attackDamage = ad;
	return ;
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " is dead... Nothing happened..."
				  << std::endl;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " tries to attack " << target << " ! "
				  << "But nothing happened..." << std::endl;
	}
	else
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name
				  << " attacks " << target
				  << " causing " << this->_attackDamage
				  << " points of damage!" << std::endl;
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " is already dead..." << std::endl;
	}
	else
	{
		this->_hitPoints-= amount;
		std::cout << "ClapTrap " << this->_name
				  << " takes " << amount
				  << " points of damage!"
				  << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " is dead... Nothing happened..."
				  << std::endl;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " does not have enough energy points... Nothing happened..."
				  << std::endl;
	}
	else
	{
		this->_energyPoints --;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name
				  << " drinks a life potion and has now "
				  << this->_hitPoints << " energy points."
				  << std::endl;
	}
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ DESTRUCTOR ~~~                                    */
/*                                                                            */
/* ************************************************************************** */

ClapTrap::~ClapTrap()
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "A ClapTrap named " << this->_name
			  << " has been destroyed !" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ NON-MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &stream, ClapTrap const &ClapTrap)
{
	stream << "The ClapTrap " << ClapTrap.getName() << " has "
		   << ClapTrap.getHitPoints() << " hit points, "
		   << ClapTrap.getEnergyPoints() << " energy points, and can cause "
		   << ClapTrap.getAttackDamage() << " attack damage." << std::endl;
	return stream;
}