/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:43:01 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/21 18:47:20 by llethuil         ###   ########lyon.fr   */
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
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A FragTrap named " << this->_name
			  << " has spawned !" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	return;
}

FragTrap::FragTrap(FragTrap const &src)
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

FragTrap	&FragTrap::operator=(FragTrap const &src)
{
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ OTHER MEMBER FUNCTIONS ~~~                        */
/*                                                                            */
/* ************************************************************************** */

std::string	FragTrap::get_name(void) const
{
	return (this->_name);
}

void	FragTrap::set_name(std::string name)
{
	this->_name = name;
	std::cout << "FragTrap is now named " << name << std::endl;
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

void		FragTrap::highFivesGuys(void)
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
	stream << "The FragTrap " << FragTrap.get_name() << " has "
		   << FragTrap.get_hp() << " hit points, "
		   << FragTrap.get_ep() << " energy points, and can cause "
		   << FragTrap.get_ad() << " attack damage." << std::endl;
	return stream;
}