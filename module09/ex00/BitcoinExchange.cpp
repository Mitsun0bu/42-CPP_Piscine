/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:12:41 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/23 12:52:24 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ CONSTRUCTOR ~~~                             */
/*                                                                            */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange(void)
{
    // std::cout   << YELLOW
    //             << "[CONSTRUCTOR] : BitcoinExchange created"
    //             << END
    //             << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ COPY CONSTRUCTOR ~~~                          */
/*                                                                            */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
    *this = src;
}

/* ************************************************************************** */
/*                                                                            */
/*                    ~~~ ASSIGNMENT OPERATOR OVERLOAD ~~~                    */
/*                                                                            */
/* ************************************************************************** */

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if (this != &src)
    {
        exchange_rates_map  = src.exchange_rates_map;
        date_string         = src.date_string;
        value_string        = src.value_string;
        value_number        = src.value_number;
        exchange_rate       = src.exchange_rate;
    }
    return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                             ~~~ DESTRUCTOR ~~~                             */
/*                                                                            */
/* ************************************************************************** */

BitcoinExchange::~BitcoinExchange(void)
{
    // std::cout   << YELLOW
    //             << "[DESTRUCTOR] : BitcoinExchange destroyed"
    //             << END
    //             << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                         ~~~ PUBLIC METHODS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

void BitcoinExchange::parseDataBaseFile(const std::string& db_file_name)
{
    std::ifstream   db_file(db_file_name);
    if (!db_file)
        throw (OpenDataBaseError());

    std::string line_string;
    std::string date;
    
    // IGNORE THE HEADER LINE
    std::getline(db_file, line_string);

    // ADD THE DATE AND CORRESPONDING EXCHANGE RATE TO THE MAP
    double  exchange_rate;
    while (std::getline(db_file, line_string))
    {
        std::istringstream line_stream(line_string);
        std::getline(line_stream, date, ',');
        line_stream >> exchange_rate;
        exchange_rates_map[date] = exchange_rate;
    }
}

void BitcoinExchange::parseInputLine(const std::string& line_string)
{
    std::istringstream  line_stream(line_string);

    // GET THE DATE AND VALUE FROM THE LINE
    if (std::getline(line_stream, date_string, '|') && std::getline(line_stream, value_string))
    {
        parseDate();
        parseValue();
    }
    else
        throw (BadInputError());
}

void BitcoinExchange::updateExchangeRate(void)
{
    std::map<std::string, double>::const_iterator it = exchange_rates_map.upper_bound(date_string);

    if (it == exchange_rates_map.begin())
        throw (DateNotFoundError());
    --it;

    exchange_rate = it->second;
}

void BitcoinExchange::printResult()
{
    std::cout   << date_string
                << " => " << value_number
                << " = " << value_number * exchange_rate
                << std::endl;
}

void BitcoinExchange::printCaughtError(const std::exception& e)
{
    std::cout   << RED
                << "[ERROR] : "
                << e.what()
                << END
                << std::endl;
}

void BitcoinExchange::printUsage(void)
{
    std::cerr   << BLUE
                << "[USAGE] : ./btc [input file name]"
                << END
                << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                         ~~~ PRIVATE METHODS ~~~                            */
/*                                                                            */
/* ************************************************************************** */

void BitcoinExchange::parseValue(void)
{
    if (value_string.empty())
        throw (MissingValueError());

    try
    {
        value_number = std::stod(value_string);
    }
    catch (...)
    {
       throw (MissingValueError());
    }

    if (value_number < 0)
        throw (NegativeValueError());
    else if (value_number > 1000)
        throw (ValueTooLargeError());
}

bool isLeapYear(int year)
{
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        return (true);
    return (false);
}

int daysInMonth(int year, int month)
{
    int days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year) == true)
        return (29);       
    return (days_per_month[month - 1]);
}

void BitcoinExchange::parseDate(void)
{
    std::tm tm_date     = {};
    
    const char *result  = strptime(date_string.c_str(), "%Y-%m-%d", &tm_date);
    if (result == NULL)
        throw (InvalidDateError());

    int year    = tm_date.tm_year + 1900;
    int month   = tm_date.tm_mon + 1;
    int day     = tm_date.tm_mday;

    if (month < 1 || month > 12 || day < 1 || day > daysInMonth(year, month))
        throw (InvalidDateError());
}