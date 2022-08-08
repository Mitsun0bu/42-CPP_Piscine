/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:04:33 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/08 17:08:30 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef EASYFIND_HPP
# define EASYFIND_HPP

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <list>
# include <algorithm>
# include <exception>

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
/*                             ~~~ TEMPLATE ~~~                               */
/*                                                                            */
/* ************************************************************************** */

class NotFoundException : public std::exception
{
	public:

		const char*	what () const throw ()
		{
			std::cout << RED << "[EXCEPTION] : " << END;
			return ("Element not found !");
		}
};

template <typename T>
void	easyfind(T batch, int elem)
{
	if (std::find(batch.begin(), batch.end(), elem) != batch.end())
		std::cout << elem << " has been found !" << std::endl;
	else
		throw NotFoundException();
}


# endif