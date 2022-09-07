/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:20:48 by llethuil          #+#    #+#             */
/*   Updated: 2022/09/07 10:44:38 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef WHATEVER_HPP
# define WHATEVER_HPP

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

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
/*                            ~~~ TEMPLATES ~~~                               */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void swap(T &x, T &y)
{
    T temp;

    temp = x;
    x = y;
    y = temp;

    return ;
}

template <typename T>
T const & max(T const & x, T const & y)
{
    if (x > y)
        return x;
    else
        return y;
}

template <typename T>
T const & min(T const & x, T const & y)
{
    if (x < y)
        return x;
    else
        return y;
}

# endif