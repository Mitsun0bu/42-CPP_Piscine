/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:21:54 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/18 14:27:23 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ CONSTRUCTORS ~~~                                  */
/*                                                                            */
/* ************************************************************************** */

ClapTrap::ClapTrap(void) : _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "A ClapTrap with no name has spawned !" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	if (this->_name.empty())
		std::cout << "A ClapTrap with no name has spawned !" << std::endl;
	else
		std::cout << "A ClapTrap named " << this->_name << " has spawned !" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	if (src._name.empty())
		std::cout << "A ClapTrap with no name has been duplicated !" << std::endl;
	else
		std::cout << "A ClapTrap named " << this->_name << " has been duplicated !" << std::endl;
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

std::string	ClapTrap::get_name(void) const
{
	if (this->_name.empty())
		return ("---");
	return (this->_name);
}

int	ClapTrap::get_hp(void) const
{
	return (this->_hit_points);
}

int	ClapTrap::get_ep(void) const
{
	return (this->_energy_points);
}

int	ClapTrap::get_ad(void) const
{
	return (this->_attack_damage);
}

void	ClapTrap::set_name(std::string name)
{
	if (this->_name.empty())
	{
		this->_name = name;
		std::cout << "A ClapTrap with no name has been named : " << name << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << name;
		this->_name = name;
		std::cout << " is now named " << name << std::endl;
	}
	return ;
}

void	ClapTrap::set_hp(int hp)
{
	this->_hit_points = hp;
	return ;
}

void	ClapTrap::set_ep(int ep)
{
	this->_energy_points = ep;
	return ;
}

void	ClapTrap::set_ad(int ad)
{
	this->_attack_damage = ad;
	return ;
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " is dead... Nothing happened..."
				  << std::endl;
	}
	else if (this->_energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " tries to attack " << target << " ! "
				  << "But nothing happened..." << std::endl;
	}
	else
	{
		this->_energy_points--;
		std::cout << "ClapTrap " << this->_name
				  << " attacks " << target
				  << " causing " << this->_attack_damage
				  << " points of damage!" << std::endl;
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " is already dead..." << std::endl;
	}
	else
	{
		this->_hit_points-= amount;
		std::cout << "ClapTrap " << this->_name
				  << " takes " << amount
				  << " points of damage!"
				  << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " is dead... Nothing happened..."
				  << std::endl;
	}
	else if (this->_energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " does not have enough energy points... Nothing happened..."
				  << std::endl;
	}
	else
	{
		this->_energy_points --;
		this->_hit_points += amount;
		std::cout << "ClapTrap " << this->_name
				  << " drinks a life potion and has now "
				  << this->_hit_points << " energy points."
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
	if (this->_name.empty())
		std::cout << "A ClapTrap with no name has been destroyed !" << std::endl;
	else
		std::cout << "A ClapTrap named " << this->_name << " has been destroyed !" << std::endl;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ NON-MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &stream, ClapTrap const &ClapTrap)
{
	stream << "The ClapTrap " << ClapTrap.get_name() << " has "
		   << ClapTrap.get_hp() << " hit points, "
		   << ClapTrap.get_ep() << " energy points, and can cause "
		   << ClapTrap.get_ad() << " attack damage." << std::endl;
	return stream;
}