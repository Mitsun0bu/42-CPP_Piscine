#include "BitcoinExchange.hpp"

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
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

void BitcoinExchange::parseDataBaseFile(const std::string& db_file_name)
{
    std::ifstream   db_file(db_file_name);
    if (!db_file)
        throw (OpenDataBaseError());

    std::string     line_string;
    std::string     date;
    
    // IGNORE THE HEADER LINE
    std::getline(db_file, line_string);

    // ADD THE DATE AND CORRESPONDING EXCHANGE RATE TO THE MAP
    double          exchange_rate;
    while (std::getline(db_file, line_string))
    {
        std::istringstream line_stream(line_string);
        std::getline(line_stream, date, ',');
        line_stream >> exchange_rate;
        exchange_rates_map[date] = exchange_rate;
    }
}

void BitcoinExchange::process(void)
{        
        updateExchangeRate();
        printResult();
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

void BitcoinExchange::parseDate(void)
{
    std::tm     tm_date = {};
    const char* result  = strptime(date_string.c_str(), "%Y-%m-%d", &tm_date);
    
    if (result == NULL)
        throw (InvalidDateError());
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
