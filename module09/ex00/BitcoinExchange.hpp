/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:09:30 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/17 18:59:37 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
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
/*                            ~~~ CLASS DEFINITION ~~~                        */
/*                                                                            */
/* ************************************************************************** */

class BitcoinExchange
{
    public:
        BitcoinExchange(const std::string& dataFileName);
        double getExchangeRate(const std::string& date) const;

    private:
        std::map<std::string, double> exchangeRatesMap;
};

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ ENUM DEFINITION ~~~                          */
/*                                                                            */
/* ************************************************************************** */

enum ValueValidationResult
{
    VALID_VALUE = 0,
    VALUE_MISSING,
    VALUE_NEGATIVE,
    VALUE_TOO_LARGE
};

/* ************************************************************************** */
/*                                                                            */
/*                    ~~~ NON MEMBER FUNCTIONS PROTOTYPES ~~~                 */
/*                                                                            */
/* ************************************************************************** */


bool checkMissingInputFileName(int argc);
bool parseInputLine(const std::string& line, std::string& date, double& value);
bool isDateValid(const std::string& date);
ValueValidationResult isValueValid(const std::string& value_str);
void printValueErrorMessage(ValueValidationResult validationResult, const std::string& lineString);

#endif