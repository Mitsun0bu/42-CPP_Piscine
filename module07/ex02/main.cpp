/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:34:41 by llethuil          #+#    #+#             */
/*   Updated: 2022/09/07 14:46:08 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

int	main()
{
	Array<int>	emptyArray;
	Array<int>	intArray(5);
	Array<int>	intArrayCpy1(intArray);

	std::cout << std::endl;
	std::cout << "TEST - ARRAY OF INT (n = 5, n[1] = 67)" << std::endl;

	intArray[1] = 67;
	try
	{
		std::cout << "intArray[1] = " << intArray[18] << std::endl;
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


// #define MAX_VAL 25

// int main(int, char**)
// {
// 	Array<int> numbers(MAX_VAL);

// 	int* mirror = new int[MAX_VAL];

// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	std::cout << std::endl;

// 	std::cout << GREEN << "[TEST - ASSIGNATION OPERATOR AND COPY CONSTRUCTOR]" << END << std::endl;
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}
// 	std::cout << std::endl;

// 	std::cout << GREEN << "[TEST - COMPARISON BETWEEN MIRROR AND NUMBERS ARRAYS]" << END << std::endl;
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 		std::cout << "mirror[" << i << "]	=	" << mirror[i] << "	and	";
// 		std::cout << "numbers[" << i << "]	=	" << numbers[i] << std::endl;
// 	}
// 	std::cout << std::endl;

// 	std::cout << GREEN << "[TEST - INVALID INDEX EXCEPTIONS]" << END << std::endl;
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	std::cout << std::endl;

// 	std::cout << GREEN << "[TEST - REDEFINITION OF NUMBERS[i]]" << END << std::endl;
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 		std::cout << "numbers[" << i << "]	=	" << numbers[i] << std::endl;
// 	}
// 	std::cout << std::endl;

// 	delete [] mirror;

// 	return 0;
// }
