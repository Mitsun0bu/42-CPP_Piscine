/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:43:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/03 11:50:27 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		argNumberError();
	else
	{
		Converter	converter(av[1]);

		if (converter.argIsChar())
			converter.handleChar();
		else if (converter.argIsInt())
			converter.handleInt();
		else if (converter.argIsFloat())
			converter.handleFloat();
		else if (converter.argIsDouble())
			converter.handleDouble();
		else 
			argInvalidError();
	}
	return (0);
}

void	argNumberError(void)
{
	std::cerr << std::endl
	<< "Error : Invalid number of arguments."
	<< std::endl
	<< "Usage : ./scalar_conversion [arg_1]"
	<< std::endl
	<< std::endl;
}

void    argInvalidError(void)
{
	std::cerr << "Error : Invalid argument."
	<< " Please use char, int, float or double."
	<< std::endl
	<< "Usage : ./scalar_conversion [arg_1]"
	<< std::endl
	<< std::endl;
}