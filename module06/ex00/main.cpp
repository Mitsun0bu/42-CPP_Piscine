/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:43:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/01 18:20:26 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		argNumberError();
		return (0);
	}
	
	/*
		1 - Detect the type of the literal passed as parameter
		2 - Convert it from string to its actual type
		3 - Convert it explicitly to the three other data types
		4 - Lastly, display the results as shown in the subject.
	*/

	Converter	converter(av[1]);

	if (converter.argIsChar())
		converter.handleChar();
	else if (converter.argIsInt())
	{
		converter.argToInt();
		try
		{
			converter.intToChar();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			converter.printIntValue();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		converter.intToFloat();
		converter.intToDouble();
	}
	else if (converter.argIsFloat())
	{
		converter.argToFloat();
		converter.floatToChar();
		converter.floatToInt();
		converter.floatToDouble();
	}
	else if (converter.argIsDouble())
	{
		converter.argToDouble();
		converter.doubleToChar();
		converter.doubleToInt();
		converter.doubleToFloat();
	}
	else 
		argInvalidError();

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