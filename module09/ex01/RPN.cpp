/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:48:50 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/20 15:37:13 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ CONSTRUCTOR ~~~                             */
/*                                                                            */
/* ************************************************************************** */

RPN::RPN(void)
{
    // std::cout << YELLOW << "[CONSTRUCTOR] : RPN calculator created" << END << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ COPY CONSTRUCTOR ~~~                          */
/*                                                                            */
/* ************************************************************************** */

RPN::RPN(const RPN& src)
{
    rpnStack = src.rpnStack;
}

/* ************************************************************************** */
/*                                                                            */
/*                             ~~~ DESTRUCTOR ~~~                             */
/*                                                                            */
/* ************************************************************************** */

RPN::~RPN()
{
    // std::cout << YELLOW << "[DESTRUCTOR] : RPN calculator destroyed" << END << std::endl;
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
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

void RPN::parse(const std::string &expression)
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
            rpnStack.push(std::stoi(token));
    }
}


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

int RPN::getResult() const
{
    return (rpnStack.top());
}

/* ************************************************************************** */
/*                                                                            */
/*                         ~~~ NON MEMBER FUNCTIONS ~~~                       */
/*                                                                            */
/* ************************************************************************** */

int handleExpression(const char* expression)
{
    RPN rpnCalculator;
    
    try
    {
        rpnCalculator.parse(expression);
        rpnCalculator.process(expression);
        std::cout << GREEN << "[RESULT] : " << END << rpnCalculator.getResult() << std::endl;
    }
    catch (const InvalidTokenError& e)
    {
        std::cerr << RED << "[ERROR] : " << e.what() << END << std::endl;
        return (1);
    }
    catch (const IncompleteExpressionError& e)
    {
        std::cerr << RED << "[ERROR] : " << e.what() << END << std::endl;
        return (1);
    }
    catch (const DivByZeroError& e)
    { 
        std::cerr << RED << "[ERROR] : " << e.what() << END << std::endl;
        return (1);
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << RED << "[ERROR] : " << e.what() << END << std::endl;
        return (1);
    }
    
    return (0);
}