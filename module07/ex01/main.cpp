/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:39:15 by llethuil          #+#    #+#             */
/*   Updated: 2022/09/07 11:17:31 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"

int main(void)
{
	int			intTab[5] = {0, 1, 2, 3, 4};
	std::string	strTab[5] = {"Mitsunobu", "Mathilde", "Burton"};
	char		charTab[5] = {'M', 'i', 't', 's', 'u'};

	std::cout << std::endl;
	std::cout << "TEST ITER TEMPLATE WITH INT TAB" << std::endl;
	::iter<int>(intTab, 5, printAnyTabContent<int>);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "TEST ITER TEMPLATE WITH STR TAB" << std::endl;
	::iter<std::string>(strTab, 3, printAnyTabContent<std::string>);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "TEST ITER TEMPLATE WITH CHAR TAB" << std::endl;
	::iter<char>(charTab, 5, printAnyTabContent<char>);
	std::cout << std::endl;

	std::cout << std::endl;

	return (0);
}

// class Awesome
// {
// 	public :

// 			Awesome(void):_n(42){}

// 		int	get() const
// 		{
// 			return (this->_n);
// 		}

// 	private :

// 		int	_n;
//  };

// std::ostream& operator<<(std::ostream& stream, const Awesome &rhs)
// {
// 	stream << rhs.get();
// 	return (stream);
// }

// template<typename T>
// void print(T const & x)
// {
// 	std::cout << x << std::endl;
// 	return ;
// }

// int main(void)
// {
// 	int tab[] = {0, 1, 2, 3, 4};
// 	Awesome tab2[5];

// 	iter(tab, 5, print);
// 	iter(tab2, 5, print);

// 	return (0);
// }