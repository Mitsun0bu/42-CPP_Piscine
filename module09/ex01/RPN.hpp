/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:28:10 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/20 15:35:02 by llethuil         ###   ########.fr       */
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
/*                        ~~~ EXCEPTIONS DEFINITION ~~~                       */
/*                                                                            */
/* ************************************************************************** */

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
/*                           ~~~ ENUM DEFINITION ~~~                          */
/*                                                                            */
/* ************************************************************************** */

enum parsingCode
{
    VALID_EXPRESSION        = 0,
    INCOMPLETE_EXPRESSION   = -1,
    DIV_BY_ZERO             = -2,
    INVALID_TOKEN           = -3
};

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ CLASS DEFINITION ~~~                        */
/*                                                                            */
/* ************************************************************************** */

class RPN
{
    public:

                            RPN();
                            RPN(const RPN& src);
                            ~RPN();

        RPN&                operator=(const RPN& src);
    
        void                parse(const std::string &expression);
        void                process(const std::string &expression);
        int                 getResult() const;
        
    private:

        std::stack<int>     rpnStack;
        void                doMath(std::string token);
};

/* ************************************************************************** */
/*                                                                            */
/*                    ~~~ NON MEMBER FUNCTIONS PROTOTYPES ~~~                 */
/*                                                                            */
/* ************************************************************************** */

void    printError(int result);
int     handleExpression(const char* expression);

#endif