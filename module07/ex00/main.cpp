/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:08:40 by llethuil          #+#    #+#             */
/*   Updated: 2022/09/07 11:11:35 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "whatever.hpp"

int main(void)
{
	int a = 2;
	int b = 3;

	std::cout << GREEN << "[TEST - ON INT VALUES]" << END << std::endl;
	::swap<int>( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min<int>( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max<int>( a, b ) << std::endl;
	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << GREEN << "[TEST - ON STRING VALUES]" << END << std::endl;
	::swap<std::string>(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min<std::string>( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max<std::string>( c, d ) << std::endl;

	return (0);
}

// class Awesome
// {
// 	public :

// 					Awesome(void):_n(0){}
// 					Awesome(int n):_n(n){}

// 		Awesome&	operator=(Awesome& a)
// 		{
// 			_n = a._n;
// 			return *this;
// 		}
// 		bool		operator==(Awesome const & rhs) const
// 		{
// 			return (this->_n == rhs._n);
// 		}
// 		bool		operator!=(Awesome const & rhs) const
// 		{
// 			return (this->_n != rhs._n);
// 		}
// 		bool		operator>(Awesome const & rhs) const
// 		{
// 			return (this->_n > rhs._n);
// 		}
// 		bool		operator<(Awesome const & rhs) const
// 		{
// 			return (this->_n < rhs._n);
// 		}
// 		bool		operator>=(Awesome const & rhs) const
// 		{
// 			return (this->_n >= rhs._n);
// 		}
// 		bool		operator<=(Awesome const & rhs) const
// 		{
// 			return (this->_n <= rhs._n);
// 		}
// 		int			get_n() const
// 		{
// 			return (_n);
// 		}

// 	private :

// 		int			_n;
//  };

// std::ostream& operator<<(std::ostream& stream, const Awesome &a)
// {
// 	stream << a.get_n();
// 	return (stream);
// }

// int main(void)
// {
// 	Awesome a(2), b(4);

// 	swap(a,b);
// 	std::cout << a << " " << b << std::endl;
// 	std::cout << max(a, b) << std::endl;
// 	std::cout << min(a, b) << std::endl;

// 	return (0);
// }
