/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:43:01 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/13 16:57:13 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ CONSTRUCTORS ~~~                                  */
/*                                                                            */
/* ************************************************************************** */

FragTrap::FragTrap(void)
{
	std::cout << "A default FragTrap\thas spawned !" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->_name << " : Lugia!" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	return;
}

FragTrap::FragTrap(FragTrap const &src)
{
	if (src._name.empty())
		std::cout << "A default FragTrap has been duplicated !" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " has been duplicated !" << std::endl;
	*this = src;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ OPERATOR OVERLOAD ~~~                             */
/*                                                                            */
/* ************************************************************************** */

FragTrap	&FragTrap::operator=(FragTrap const &src)
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

std::string	FragTrap::get_name(void) const
{
	if (this->_name.empty())
		return ("Oh-Oh");
	return (this->_name);
}

void	FragTrap::set_name(std::string name)
{
	this->_name = name;
	std::cout << "FragTrap is now named "
			  << name << std::endl;
	return ;
}

void	FragTrap::attack(std::string const &target)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "FragTrap " << this->_name
				  << " is dead... Nothing happened..."
				  << std::endl;
	}
	else if (this->_energy_points <= 0)
	{
		std::cout << "FragTrap " << this->_name
				  << " tries to attack " << target << " ! "
				  << "But nothing happened..." << std::endl;
	}
	else
	{
		this->_energy_points--;
		std::cout << "FragTrap " << this->_name
				  << " attacks " << target
				  << " causing " << this->_attack_damage
				  << " points of damage!" << std::endl;
	}
	return ;
}

void		FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << this->_name
			<< " has been captured!"
			<< " This deserve a high five, give me a high five !"
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
	if (this->_name.empty())
		std::cout << "A default FragTrap has disappeared !" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " has disappeared !" << std::endl;
	return ;

}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ NON-MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

std::ostream	&operator<<(std::ostream &stream, FragTrap const &FragTrap)
{
	stream << "FragTrap " << FragTrap.get_name() << "\thas "
		   << FragTrap.get_hp() << " hit points, "
		   << FragTrap.get_ep() << " energy points, and can cause "
		   << FragTrap.get_ad() << " attack damage." << std::endl;
	return stream;
}