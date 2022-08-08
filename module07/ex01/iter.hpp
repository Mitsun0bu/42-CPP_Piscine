/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:20:48 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/05 16:45:25 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ TEMPLATES ~~~                               */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void    iter(const T* array, int len, void func(const T&))
{
	for (int i = 0; i < len; i++)
		func(array[i]);
}

template<typename T>
void    printAnyTabContent(const T& content)
{
	std::cout << content << " ";
}