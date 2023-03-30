/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:09:30 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/30 17:24:44 by llethuil         ###   ########.fr       */
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

class MissingInfileError : public std::runtime_error
{
    public:
        MissingInfileError() : std::runtime_error("MISSING INPUT FILE NAME") {}
};

class EmptyInfileError : public std::runtime_error
{
    public:
        EmptyInfileError() : std::runtime_error("INPUT FILE IS EMPTY OR IS A DIRECTORY") {}
};

class OpenInfileError : public std::runtime_error
{
    public:
        OpenInfileError() : std::runtime_error("COULD NOT OPEN INPUT FILE") {}
};

class OpenDataBaseError : public std::runtime_error
{
    public:
        OpenDataBaseError() : std::runtime_error("COULD NOT OPEN DATA BASE") {}
};

class BadInfileHeaderPositionError : public std::runtime_error
{
    public:
        BadInfileHeaderPositionError() : std::runtime_error("INFILE HEADER NOT AT THE TOP OF INFILE") {}
};

class DateNotFoundError : public std::runtime_error
{
    public:
        DateNotFoundError() : std::runtime_error("DATE NOT FOUND IN DATA BASE") {}
};

class InvalidDateError : public std::runtime_error
{
    public:
        InvalidDateError() : std::runtime_error("INVALID INPUT DATE") {}
};

class MissingValueError : public std::runtime_error
{
    public:
        MissingValueError() : std::runtime_error("MISSING INPUT VALUE") {}
};

class NegativeValueError : public std::runtime_error
{
    public:
        NegativeValueError() : std::runtime_error("NEGATIVE INPUT VALUE") {}
};

class ValueTooLargeError : public std::runtime_error
{
    public:
        ValueTooLargeError() : std::runtime_error("VALUE TOO LARGE") {}
};

class BadInputError : public std::runtime_error
{
    public:
        BadInputError() : std::runtime_error("BAD INPUT, MISSING DATE OR VALUE") {}
};

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ CLASS DEFINITION ~~~                        */
/*                                                                            */
/* ************************************************************************** */

class BitcoinExchange
{
    public:
		/* CONSTRUCTOR */
                                        BitcoinExchange(void);
		/* COPY CONSTRUCTOR */
                                        BitcoinExchange(const BitcoinExchange& src);
        /* ASSIGNATION OPERATOR OVERLOAD */
        BitcoinExchange&                operator=(const BitcoinExchange& src);    
        /* DESTRUCTOR */
                                        ~BitcoinExchange(void);
        
        /* PUBLIC METHODS */
        void                            parseDataBaseFile(const std::string& data_file_name);
        void                            parseInputLine(const std::string& line_string);
        void                            updateExchangeRate(void);
        void                            printResult(void);
        void                            printCaughtError(const std::exception& e);
        void                            printUsage(void);

        /* GETTERS */
        std::string                     getDateString(void) const;
        std::string                     getValueString(void) const;

    private:

        /* PRIVATE ATTRIBUTES */
        std::map<std::string, double>   exchange_rates_map;
        std::string                     date_string;
        std::string                     value_string;
        double                          value_number;
        double                          exchange_rate;

        /* PRIVATE METHODS */
        void                            parseDate(void);
        void                            parseValue(void);
};

#endif