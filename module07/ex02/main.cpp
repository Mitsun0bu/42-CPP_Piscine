/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:34:41 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/08 16:06:28 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

int	main()
{
	Array<int>	intArray(5);
	Array<int>	intArrayCpy1(intArray);

	std::cout << std::endl;
	std::cout << "TEST - ARRAY OF INT (n = 5, n[1] = 67)" << std::endl;

	intArray[1] = 67;
	try
	{
		std::cout << "intArray[1] = " << intArray[1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "TEST - COPY OF THE ARRAY OF INT (n = 5, copy done before n[1] assignation)" << std::endl;
	std::cout << "intArrayCpy1[1] = " << intArrayCpy1[1] << std::endl;

	std::cout << std::endl;
	std::cout << "TEST - COPY OF THE ARRAY OF INT (n = 5, copy done after n[1] assignation)" << std::endl;
	Array<int>	intArrayCpy2(intArray);
	std::cout << "intArrayCpy2[1] = " << intArrayCpy2[1] << std::endl;

	std::cout << std::endl;
	std::cout << "TEST - ARRAY OF STRINGS (n = 3, n[0] = \"Salut\", n[1] = \"les\", n[2] = \"gens\")" << std::endl;
	Array<std::string>	stringArray(3);

	stringArray[0] = "Salut";
	stringArray[1] = "les";
	stringArray[2] = "gens";

	for (int i = 0 ; i < stringArray.size() ; i ++)
		std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;

	std::cout << std::endl;

	return (0);
}
