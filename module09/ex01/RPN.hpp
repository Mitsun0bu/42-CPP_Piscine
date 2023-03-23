/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:28:10 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/23 09:44:46 by llethuil         ###   ########.fr       */
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

#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define ORANGE  "\x1B[34m"
#define PURPLE  "\x1B[35m"
#define BLUE    "\x1B[36m"
#define END     "\033[0m"

/* ************************************************************************** */
/*                                                                            */
/*                        ~~~ EXCEPTIONS DEFINITION ~~~                       */
/*                                                                            */
/* ************************************************************************** */

class MissingArgumentError : public std::runtime_error
{
    public:
        MissingArgumentError() : std::runtime_error("MISSING ARGUMENT") {}
};

class InvalidTokenError : public std::runtime_error
{
    public:
        InvalidTokenError() : std::runtime_error("INVALID TOKEN") {}
};

class IncompleteExpressionError : public std::runtime_error
{
    public:
        IncompleteExpressionError() : std::runtime_error("INCOMPLETE EXPRESSION") {}
};

class DivByZeroError : public std::runtime_error
{
    public:
        DivByZeroError() : std::runtime_error("DIVISION BY ZERO") {}
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
        void            printCaughtError(const std::runtime_error& e) const;
        void            printUsage() const;

    private:

        /* PRIVATE ATTRIBUTES */
        std::stack<int> rpnStack;

        /* PRIVATE METHODS */
        void            doMath(std::string token);
};

#endif