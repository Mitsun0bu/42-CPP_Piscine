/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:28:10 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/22 16:54:23 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept> 
#include <string>

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
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
/*                        ~~~ EXCEPTIONS DEFINITION ~~~                       */
/*                                                                            */
/* ************************************************************************** */

class MissingArgumentError : public std::runtime_error
{
    public:
        MissingArgumentError() : std::runtime_error("[ERROR] : MISSING ARGUMENT") {}
};

class InvalidTokenError : public std::runtime_error
{
    public:
        InvalidTokenError() : std::runtime_error("[ERROR] : INVALID TOKEN") {}
};

class IncompleteExpressionError : public std::runtime_error
{
    public:
        IncompleteExpressionError() : std::runtime_error("[ERROR] : INCOMPLETE EXPRESSION") {}
};

class DivByZeroError : public std::runtime_error
{
    public:
        DivByZeroError() : std::runtime_error("[ERROR] : DIVISION BY ZERO") {}
};

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ CLASS DEFINITION ~~~                        */
/*                                                                            */
/* ************************************************************************** */

class RPN
{
    public:

		/* CONSTRUCTOR */
                        RPN();
		/* COPY CONSTRUCTOR */
                        RPN(const RPN& src);
        /* ASSIGNMENT OPERATOR OVERLOAD */
        RPN&            operator=(const RPN& src);
        /* DESTRUCTOR */
                        ~RPN();
    
        /* PUBLIC METHODS */
        void            parseArgument(const std::string &expression);
        void            process(const std::string &expression);
        void            printResult() const;

    private:

        /* PRIVATE ATTRIBUTES */
        std::stack<int> rpnStack;

        /* PRIVATE METHODS */
        void            doMath(std::string token);
};

#endif