/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:15:18 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/09 18:35:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <stack>

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
class MutantStack : public std::stack<T>
{
	public :

		/* constructors 										*/
						MutantStack(void);
						MutantStack(const MutantStack& src);

		/* operator overload 									*/
		MutantStack<T>&	operator=(MutantStack<T> const & src);

		/* typedefs												*/
		typedef typename std::stack<T>::container_type	container_type;
		typedef typename container_type::iterator		iterator;

		/* iterator functions									*/
		iterator				begin(void)
		{
			return (this->c.begin());
		}
		iterator				end(void)
		{
			return (this->c.end());
		}

		/* destructor 											*/
						~MutantStack(void);
};

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack(void)
{
	std::cout << BLUE << "[CONSTRUCTOR] : " << END
			  << "A MutantStack has been created !" << std::endl;
	return ;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& src)
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
MutantStack<T>&	MutantStack<T>::operator=(MutantStack<T> const &src)
{
	static_cast < std::stack<T> > (*this) = static_cast < std::stack<T> > (src);
	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << PURPLE << "[DESTRUCTOR] : " << END
				<< "A MutantStack has been destroyed !" << std::endl;

	return ;
}

# endif