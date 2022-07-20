/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:20:31 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/20 15:54:52 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ CONSTRUCTORS ~~~                                  */
/*                                                                            */
/* ************************************************************************** */

ScavTrap::ScavTrap(void)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			<< "A ScavTrap named " << this->_name
			<< " has spawned !" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A ScavTrap named " << this->_name
			  << " has spawned !" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src)
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
	return (this->_name);
}

void	ScavTrap::set_name(std::string name)
{
	this->_name = name;
	std::cout << "ScavTrap is now named " << name << std::endl;
	return ;
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ScavTrap " << this->_name
				  << " is dead... Nothing happened..."
				  << std::endl;
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
	stream << "The ScavTrap " << ScavTrap.get_name() << " has "
		   << ScavTrap.get_hp() << " hit points, "
		   << ScavTrap.get_ep() << " energy points, and can cause "
		   << ScavTrap.get_ad() << " attack damage." << std::endl;
	return stream;
}