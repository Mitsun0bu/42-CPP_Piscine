/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:23:35 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/24 13:49:09 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAIN_HPP
# define MAIN_HPP

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include "A_Animal.hpp"
# include "Brain.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ COLOR DEFINES ~~~                           */
/*                                                                            */
/* ************************************************************************** */

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define END "\033[0m"

/* ************************************************************************** */
/*                                                                            */
/*                             ~~~ PROTOTYPES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

void	testArray();
void	testAssignmentOperator(void);
void	testCopyConstructor(void);

# endif