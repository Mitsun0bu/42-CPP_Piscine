/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:20:31 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/18 15:30:24 by llethuil         ###   ########lyon.fr   */
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
	std::cout << "A ScavTrap with no name has spawned !" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	std::cout << "SCAV TRAP ENERGY POINT " << this->get_ep() << std::endl;
	this->_attack_damage = 20;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	if (this->_name.empty())
		std::cout << "A ScavTrap with no name has spawned !" << std::endl;
	else
		std::cout << "A ScavTrap named " << this->_name << " has spawned !" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	std::cout << "SCAV TRAP ENERGY POINT " << this->get_ep() << std::endl;
	this->_attack_damage = 20;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	if (src._name.empty())
		std::cout << "A ScavTrap with no name has been duplicated !" << std::endl;
	else
		std::cout << "A ScavTrap named " << this->_name << " has been duplicated !" << std::endl;
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
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	return *this;
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ OTHER MEMBER FUNCTIONS ~~~                        */
/*                                                                            */
/* ************************************************************************** */

std::string	ScavTrap::get_name(void) const
{
	if (this->_name.empty())
		return ("---");
	return (this->_name);
}

void	ScavTrap::set_name(std::string name)
{
	if (this->_name.empty())
	{
		this->_name = name;
		std::cout << "A ScavTrap with no name has been named : " << name << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << name;
		this->_name = name;
		std::cout << " is now named " << name << std::endl;
	}
	return ;
}


void	ScavTrap::attack(std::string const &target)
{
	if (this->_hit_points == 0)
	{
		std::cout << "ScavTrap " << this->_name
				  << " is dead... Nothing happened..."
				  << std::endl;
	}
	else if (this->_energy_points == 0)
	{
		std::cout << "ScavTrap " << this->_name
				  << " tries to attack " << target << " ! "
				  << "But nothing happened..." << std::endl;
	}
	else
	{
		this->_energy_points--;
		std::cout << "ScavTrap " << this->_name
				  << " attacks " << target
				  << " causing " << this->_attack_damage
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
	if (this->_name.empty())
		std::cout << "A ScavTrap with no name has been destroyed !" << std::endl;
	else
		std::cout << "A ScavTrap named " << this->_name << " has been destroyed !" << std::endl;
	return ;

}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ NON-MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &stream, ScavTrap const &ScavTrap)
{
	stream << "The ScavTrap " << ScavTrap.get_name() << " has "
		   << ScavTrap.get_hp() << " hit points, "
		   << ScavTrap.get_ep() << " energy points, and can cause "
		   << ScavTrap.get_ad() << " attack damage." << std::endl;
	return stream;
}