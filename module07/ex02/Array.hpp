/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:42:24 by llethuil          #+#    #+#             */
/*   Updated: 2022/09/07 11:55:24 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef ARRAY_HPP
# define ARRAY_HPP

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

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
/*                             ~~~ TEMPLATE ~~~                               */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
class Array
{
	public:

		/* constructors										*/
					Array(void);
					Array(unsigned int n);
					Array(const Array& src);

		/* operator overload								*/
		Array<T>&	operator=(const Array<T>& src);
		T&			operator[](int i);

		/* member functions									*/
		int			size(void) const;

		/* exceptions										*/
		class	InvalidIndexException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		/* destructor										*/
				~Array(void);

	private :

		/* private attributes								*/
		T*		_array;
		int		_size;
};

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "An empty array has been created !" << std::endl;

	this->_array = new T [0];

	return ;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			<< "An array of " << n << " elements has been created !" << std::endl;

	this->_array = new T [n];

	for (unsigned int i = 0; i < n; i++)
		this->_array[i] = 0;

	this->_size = n;

	return ;
}

template <>
Array<std::string>::Array(unsigned int n)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			<< "An array of " << n << " elements has been created !" << std::endl;

	this->_array = new std::string [n];

	for (unsigned int i = 0; i < n; i++)
		this->_array[i] = "";

	this->_size = n;

	return ;
}

template <typename T>
Array<T>::Array(const Array& src)
{
	std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
			  << "An array has been duplicated !" << std::endl;

	*this = src;

	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>&		Array<T>::operator=(Array<T> const &src)
{
	this->_array = new T[src.size()];

	for (int i = 0; i < src.size(); i ++)
		this->_array[i] = src._array[i];

	this->_size = src.size();

	return (*this);
}

template <typename T>
T&	Array<T>::operator[] (int index)
{
	if (index >= 0 && index < this->size())
		return (this->_array[index]);
	else
		throw InvalidIndexException();
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
int			Array<T>::size(void) const
{
	return (this->_size);
}

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ EXCEPTIONS ~~~                            */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
const char*	Array<T>::InvalidIndexException::what() const throw()
{
	std::cout << RED << "[EXCEPTION] : " << END;
	return ("Invalid index !");
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::~Array(void)
{
		std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "An array has been destroyed !" << std::endl;

	delete this->_array;

	return ;
}

template <>
Array<std::string>::~Array(void)
{
		std::cout << PURPLE << "[DESTRUCTOR] : " << END
			  << "An array has been destroyed !" << std::endl;

	delete [] this->_array;

	return ;
}

# endif