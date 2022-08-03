/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:32:52 by lle-briq          #+#    #+#             */
/*   Updated: 2022/08/03 18:05:12 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	Data		*data;
	uintptr_t	serialized;
	Data		*deserialized;

	data = new Data();
	std::cout << "Data address\t\t[ data ]\t\t\t:\t" << data << std::endl;
	std::cout << "Date value\t\t[ data->getValue() ]\t\t:\t" << data->getValue() << std::endl;
	std::cout << std::endl;

	serialized = serialize(data);
	std::cout << "serialize\t\t[ serialize(data) ]\t\t:\t" << serialized << std::endl;
	std::cout << std::endl;

	deserialized = deserialize(serialized);
	std::cout << "deserialized\t\t[ deserialize(serialized) ]\t:\t" << deserialized << std::endl;
	std::cout << "deserialized value\t[ deserialized->getValue() ]\t:\t" << deserialized->getValue() << std::endl;

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
