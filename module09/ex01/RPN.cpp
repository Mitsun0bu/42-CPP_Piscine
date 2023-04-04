/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:48:50 by llethuil          #+#    #+#             */
/*   Updated: 2023/04/04 11:58:43 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ CONSTRUCTOR ~~~                             */
/*                                                                            */
/* ************************************************************************** */

RPN::RPN(void)
{
    // std::cout   << YELLOW
    //             << "[CONSTRUCTOR] : RPN calculator created"
    //             << END
    //             << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ COPY CONSTRUCTOR ~~~                          */
/*                                                                            */
/* ************************************************************************** */

RPN::RPN(const RPN& src)
{
    *this = src;
}

/* ************************************************************************** */
/*                                                                            */
/*                    ~~~ ASSIGNMENT OPERATOR OVERLOAD ~~~                    */
/*                                                                            */
/* ************************************************************************** */

RPN& RPN::operator=(const RPN& src)
{
    if (this != &src)
        rpnStack = src.rpnStack;
    return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                             ~~~ DESTRUCTOR ~~~                             */
/*                                                                            */
/* ************************************************************************** */

RPN::~RPN(void)
{
    // std::cout   << YELLOW
    //             << "[DESTRUCTOR] : RPN calculator destroyed"
    //             << END
    //             << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                         ~~~ PUBLIC METHODS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

void RPN::parseArgument(const std::string &expression)
{
    std::istringstream  expressionStream(expression);
    std::string         token;
    int                 nOperators = 0;
    int                 nOperands  = 0;

    while (expressionStream >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
            nOperators++;
        else if ((token.length() == 1 && token[0] >= '0' && token[0] <= '9')
                || (token.length() == 2 && token[0] == '-' && token[1] >= '0' && token[1] <= '9'))
            nOperands++;
        else
            throw (InvalidTokenError());
    }

    if (nOperands - nOperators != 1)
        throw (IncompleteExpressionError());
}

void RPN::process(const std::string &expression)
{
    std::istringstream  expressionStream(expression);
    std::string         token;

    while (expressionStream >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
                doMath(token);
        else
        {
            const char* tok = token.c_str();
            rpnStack.push(std::atoi(tok));
        }
    }
}

void RPN::printResult() const
{
    std::cout   << GREEN
                << "[RESULT] : "
                << END
                << rpnStack.top()
                << std::endl;
}

void RPN::printCaughtError(const std::runtime_error& e) const
{
    std::cerr   << RED
                << "[ERROR] : "
                << e.what()
                << END
                << std::endl;
}

void RPN::printUsage() const
{
    std::cerr   << BLUE
                << "[USAGE] : ./RPN \"expression\""
                << END
                << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                         ~~~ PRIVATE METHODS ~~~                            */
/*                                                                            */
/* ************************************************************************** */

void RPN::doMath(std::string token)
{
    int result = 0;

    int b = rpnStack.top();
    rpnStack.pop();

    int a = rpnStack.top();
    rpnStack.pop();

    if (token == "+")
        result = a + b;
    else if (token == "-")
        result = a - b;
    else if (token == "*")
        result = a * b;
    else if (token == "/")
    {
        if (b == 0)
            throw (DivByZeroError());
        result = a / b;
    }
    rpnStack.push(result);
}
