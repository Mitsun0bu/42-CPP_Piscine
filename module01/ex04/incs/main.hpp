/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:46:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/18 18:39:06 by llethuil         ###   ########lyon.fr   */
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
# include <fstream>

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

# define N_ARG_ERR 0
# define NO_INFILE 1
# define EMPTY_ARG_ERR 2
# define EMPTY_FILE 3

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/*      srcs/print_error.cpp */
void	printError(int errorType);

/*      srcs/replace.cpp */
void		myReplace(std::string infileName, std::string old, std::string sub, std::string outfileName);
std::string	getText(std::ifstream &infile);
int			replaceLoop(std::string text, std::string old, std::string sub, std::string outfileName);

# endif
