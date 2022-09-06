/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:32:52 by lle-briq          #+#    #+#             */
/*   Updated: 2022/09/06 14:37:47 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	Data*		data;
	uintptr_t	serialized;
	Data*		deserialized;

	data = new Data();
	data->x = 6;
	data->y = 7;

	std::cout << GREEN << "[TEST - BEFORE SERIALIZATION]" << END << std::endl;
	std::cout << "Data address		[ data ]			:	" << data
			  << std::endl;
	std::cout << "Data values		[ data->x, data->y]		:	" << data->x << ", " << data->y
			  << std::endl;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - SERIALIZATION]" << END << std::endl;
	serialized = serialize(data);
	std::cout << "serialize		[ serialize(data) ]		:	" << serialized << std::endl;

	std::cout << std::endl;

	std::cout << GREEN << "[TEST - DESERIALIZATION]" << END << std::endl;
	deserialized = deserialize(serialized);
	std::cout << "deserialized		[ deserialize(serialized) ]	:	" << deserialized << std::endl;
	std::cout << "Data values		[ data->x, data->y]		:	" << data->x << ", " << data->y << std::endl;

	delete data;

	return (0);
}

void	argNumberError(void)
{
	std::cerr << std::endl
	<< "Error : Invalid number of arguments."
	<< std::endl
	<< "Usage : ./serialize"
	<< std::endl
	<< std::endl;
}

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
