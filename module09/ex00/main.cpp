/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:33:56 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/20 09:27:40 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char* av[])
{
    if (checkMissingInputFileName(ac) == true)
        return (1);

    // OPEN THE DATA BASE FILE
    BitcoinExchange btc("data.csv");

    // OPEN THE INPUT FILE 
    std::ifstream   input_file(av[1]);
    if (!input_file)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }

    // READ THE INPUT FILE LINE BY LINE
    std::string line;
    while (std::getline(input_file, line))
    {
        std::string date;
        double      value;

        // PARSE THE LINE
        if (parseInputLine(line, date, value))
        {
            // GET THE EXCHANGE RATE
            double exchangeRate = btc.getExchangeRate(date);
            
            // PRINT THE RESULT OF THE CONVERSION
            if (exchangeRate >= 0)
                std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
            else
                std::cout << "Error: date not found in database => " << date << std::endl;
        }
    }

    return (0);
}