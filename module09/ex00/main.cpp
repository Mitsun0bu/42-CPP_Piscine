/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:33:56 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/30 17:26:49 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char* av[])
{
    // OPEN THE DATA BASE FILE
    BitcoinExchange btc;

    try
    {
        if (ac != 2)
            throw (MissingInfileError());
        
        // OPEN THE INPUT FILE 
        std::ifstream   input_file(av[1]);
        if (!input_file)
            throw (OpenInfileError());

        // CHECK IF THE INPUT FILE IS EMPTY OR IS A FOLDER
        if (input_file.is_open() && input_file.peek() == std::ifstream::traits_type::eof())
            throw (EmptyInfileError());

        btc.parseDataBaseFile("data.csv");
        
        // READ THE INPUT FILE LINE BY LINE
        std::string     line;
        int             i = 0;
        while (std::getline(input_file, line))
        {
            i ++;
            try
            {
                btc.parseInputLine(line);
                if (i == 1 && btc.getDateString() == "date" && btc.getValueString() == "value")
                    continue ;
                if (btc.getDateString() == "date" && btc.getValueString() == "value")
                    throw (BadInfileHeaderPositionError());
                btc.updateExchangeRate();
                btc.printResult();
            }
            catch (const std::exception& e)
            {
                btc.printCaughtError(e);
            }
        }
    }
    catch (MissingInfileError &e)
    {
        btc.printCaughtError(e);
        btc.printUsage();
        return (1);
    }
    catch (std::exception & e)
    {
        btc.printCaughtError(e);
        return (1);
    }

    return (0);
}