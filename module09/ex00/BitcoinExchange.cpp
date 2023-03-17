#include "BitcoinExchange.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ CONSTRUCTOR ~~~                             */
/*                                                                            */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange(const std::string& dataFileName)
{
    std::ifstream   dataFile(dataFileName);
    std::string     lineString;
    std::string     date;
    double          exchangeRate;

    // IGNORE THE HEADER LINE
    std::getline(dataFile, lineString);

    // ADD THE DATE AND CORRESPONDING EXCHANGE RATE TO THE MAP
    while (std::getline(dataFile, lineString))
    {
        std::istringstream lineStream(lineString);
        std::getline(lineStream, date, ',');
        lineStream >> exchangeRate;
        
        exchangeRatesMap[date] = exchangeRate;
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = exchangeRatesMap.upper_bound(date);

    if (it == exchangeRatesMap.begin())
        return (-1);
    --it;

    return (it->second);
}

/* ************************************************************************** */
/*                                                                            */
/*                         ~~~ NON MEMBER FUNCTIONS ~~~                       */
/*                                                                            */
/* ************************************************************************** */

bool checkMissingInputFileName(int argc)
{
    if (argc != 2)
    {
        std::cerr << "Error: missing input file name." << std::endl;
        return (true);
    }
    return (false);
}

bool parseInputLine(const std::string& lineString, std::string& date, double& valueNumber)
{
    std::istringstream lineStream(lineString);
    std::string valueString;

    // GET THE DATE AND VALUE FROM THE LINE
    if (std::getline(lineStream, date, '|') && std::getline(lineStream, valueString))
    {
        // CHECK IF THE DATE IS VALID
        if (!isDateValid(date))
        {
            std::cout << "Error: invalid date at line \"" << lineString << "\"" << std::endl;
            return (false);
        }

        // CHECK IF THE VALUE IS VALID
        ValueValidationResult validationResult = isValueValid(valueString);
        if (validationResult != VALID_VALUE)
        {
            printValueErrorMessage(validationResult, lineString);
            return (false);
        }

        // CONVERT THE VALUE STRING TO A DOUBLE
        valueNumber = std::stod(valueString);

        return (true);
    }

    std::cout << "Error: bad input \"" << lineString << "\"" << std::endl;

    return (false);
}

bool isDateValid(const std::string& date)
{
    std::tm tm_date = {};

    const char* result = strptime(date.c_str(), "%Y-%m-%d", &tm_date);
    if (result == NULL)
        return (false);

    return (true);
}

ValueValidationResult isValueValid(const std::string& valueString)
{
    if (valueString.empty())
        return (VALUE_MISSING);

    double value;
    try
    {
        value = std::stod(valueString);
    }
    catch (...)
    {
        return (VALUE_MISSING);
    }

    if (value < 0)
        return (VALUE_NEGATIVE);
    else if (value > 1000)
        return (VALUE_TOO_LARGE);

    return (VALID_VALUE);
}

void printValueErrorMessage(ValueValidationResult validationResult, const std::string& lineString)
{
    switch (validationResult)
    {
        case VALUE_MISSING:
            std::cout << "Error: value missing at line \"" << lineString << "\"" << std::endl;
            break;
        case VALUE_NEGATIVE:
            std::cout << "Error: negative value at line \"" << lineString << "\"" << std::endl;
            break;
        case VALUE_TOO_LARGE:
            std::cout << "Error: value too large at line \"" << lineString << "\"" << std::endl;
            break;
        case VALID_VALUE:
            break;
    }
}