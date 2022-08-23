/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:03:32 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/23 11:53:10 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ CONSTRUCTORS ~~~                                  */
/*                                                                            */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(void) : ClapTrap("---_clap_trap"), _name("---")
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			<< "A DiamondTrap named " << this->_name
			<< " has spawned !" << std::endl;
	this->_hitPoints = FragTrap::HP;
	this->_energyPoints = ScavTrap::EP;
	this->_attackDamage = FragTrap::AD;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), _name(name)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			<< "A DiamondTrap named " << this->_name
			<< " has spawned !" << std::endl;
	this->_hitPoints = FragTrap::HP;
	this->_energyPoints = ScavTrap::EP;
	this->_attackDamage = FragTrap::AD;
	return;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
		<< "A DiamondTrap named " << this->_name
		<< " has been duplicated !" << std::endl;
	*this = src;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ OPERATOR OVERLOAD ~~~                             */
/*                                                                            */
/* ************************************************************************** */

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &src)
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

std::string	DiamondTrap::getName(void) const
{
	return (this->_name);
}

void	DiamondTrap::setName(std::string name)
{
	this->_name = name;
	std::cout << "DiamondTrap is now named " << name << std::endl;
	return ;
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
	return ;
}

void		DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap is named " << this->getName()
			<< " but did you know it's a " << this->ClapTrap::_name
			<< " ?????";
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ DESTRUCTOR ~~~                                    */
/*                                                                            */
/* ************************************************************************** */

DiamondTrap::~DiamondTrap()
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
			<< "A DiamondTrap named " << this->_name
			<< " has been destroyed !" << std::endl;
	return ;

}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ NON-MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &stream, DiamondTrap const &DiamondTrap)
{
	stream << "The DiamondTrap " << DiamondTrap.getName() << " has "
		   << DiamondTrap.getHitPoints() << " hit points, "
		   << DiamondTrap.getEnergyPoints() << " energy points, and can cause "
		   << DiamondTrap.getAttackDamage() << " attack damage." << std::endl;
	return stream;
}