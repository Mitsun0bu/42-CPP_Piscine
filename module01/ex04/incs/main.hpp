/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:46:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/06 19:14:56 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

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

# define TO_DO 0
# define DONE 1

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/*      srcs/print_error.cpp */ 
void	print_error(int error_type);

/*      srcs/replace.cpp */ 
void    replace(std::string infile_name, std::string old, std::string sub, std::string outfile_name);
int     replacing_loop(std::ifstream &infile, std::string old, std::string sub, std::string outfile_name);

