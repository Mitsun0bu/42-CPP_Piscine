/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:03:32 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/18 11:48:27 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ CONSTRUCTORS ~~~                                  */
/*                                                                            */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(void) : _inherited_name("_clap_trap")
{
	std::cout << "A DiamondTrap with no name has spawned !" << std::endl;
	this->_hit_points = FragTrap::get_hp();
	this->_energy_points = ScavTrap::get_ep();
	this->_attack_damage = FragTrap::get_ad();
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), _inherited_name(name + "_clap_trap")
{
	this->_name = ClapTrap::get_name();
	if (this->_name.empty())
		std::cout << "A DiamondTrap with no name has spawned !" << std::endl;
	else
		std::cout << "A DiamondTrap named " << ClapTrap::get_name() << " has spawned !" << std::endl;
	this->_hit_points = FragTrap::get_hp();
	this->_energy_points = ScavTrap::get_ep();
	this->_attack_damage = FragTrap::get_ad();
	return;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
{
	if (src._name.empty())
		std::cout << "A DiamondTrap with no name has been duplicated !" << std::endl;
	else
		std::cout << "A DiamondTrap named " << this->_name << " has been duplicated !" << std::endl;
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

std::string	DiamondTrap::get_name(void) const
{
	return (ClapTrap::get_name());
}

void	DiamondTrap::set_name(std::string name)
{
	if (this->_name.empty())
	{
		this->_name = name;
		std::cout << "A DiamondTrap with no name has been named : " << name << std::endl;
	}
	else
	{
		std::cout << "DiamondTrap " << name;
		this->_name = name;
		std::cout << " is now named " << name << std::endl;
	}
	return ;
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
	return ;
}

void		DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap is named " << this->get_name()
			<< " but did you know it's a " << this->_inherited_name
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
	if (this->_name.empty())
		std::cout << "A DiamondTrap with no name has been destroyed !" << std::endl;
	else
		std::cout << "A DiamondTrap named " << this->_name << " has been destroyed !" << std::endl;
	return ;

}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ NON-MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &stream, DiamondTrap const &DiamondTrap)
{
	stream << "The DiamondTrap " << DiamondTrap.get_name() << " has "
		   << DiamondTrap.get_hp() << " hit points, "
		   << DiamondTrap.get_ep() << " energy points, and can cause "
		   << DiamondTrap.get_ad() << " attack damage." << std::endl;
	return stream;
}