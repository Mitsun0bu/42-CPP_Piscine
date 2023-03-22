/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:09:30 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/22 18:47:00 by llethuil         ###   ########.fr       */
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

class MissingInfileError : public std::runtime_error
{
    public:
        MissingInfileError() : std::runtime_error("[ERROR] : MISSING INPUT FILE NAME") {}
};

class OpenInfileError : public std::runtime_error
{
    public:
        OpenInfileError() : std::runtime_error("[ERROR] : COULD NOT OPEN INPUT FILE") {}
};

class OpenDataBaseError : public std::runtime_error
{
    public:
        OpenDataBaseError() : std::runtime_error("[ERROR] : COULD NOT OPEN DATA BASE") {}
};

class DateNotFoundError : public std::runtime_error
{
    public:
        DateNotFoundError() : std::runtime_error("[ERROR] : DATE NOT FOUND IN DATA BASE") {}
};

class InvalidDateError : public std::runtime_error
{
    public:
        InvalidDateError() : std::runtime_error("[ERROR] : INVALID INPUT DATE") {}
};

class MissingValueError : public std::runtime_error
{
    public:
        MissingValueError() : std::runtime_error("[ERROR] : MISSING INPUT VALUE") {}
};

class NegativeValueError : public std::runtime_error
{
    public:
        NegativeValueError() : std::runtime_error("[ERROR] : NEGATIVE INPUT VALUE") {}
};

class ValueTooLargeError : public std::runtime_error
{
    public:
        ValueTooLargeError() : std::runtime_error("[ERROR] : VALUE TOO LARGE") {}
};

class BadInputError : public std::runtime_error
{
    public:
        BadInputError() : std::runtime_error("[ERROR] : BAD INPUT") {}
};

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ CLASS DEFINITION ~~~                        */
/*                                                                            */
/* ************************************************************************** */

class BitcoinExchange
{
    public:

                                        BitcoinExchange(void);
        void                            parseDataBaseFile(const std::string& data_file_name);
        void                            process(void);
        void                            parseInputLine(const std::string& line_string);

    private:

        std::map<std::string, double>   exchange_rates_map;
        std::string                     date_string;
        std::string                     value_string;
        double                          value_number;
        double                          exchange_rate;
        void                            parseValue(void);
        void                            parseDate(void);
        void                            updateExchangeRate(void);
        void                            printResult(void);
};

#endif