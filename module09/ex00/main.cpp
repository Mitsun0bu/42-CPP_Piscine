/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:33:56 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/22 18:40:19 by llethuil         ###   ########.fr       */
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

        btc.parseDataBaseFile("data.csv");
        
        // READ THE INPUT FILE LINE BY LINE
        std::string     line;
        while (std::getline(input_file, line))
        {
            try
            {
                btc.parseInputLine(line);
                btc.process();
            }
            catch (const DateNotFoundError& e)
            {
                std::cerr   << RED
                            << e.what()
                            << END
                            << std::endl;
                continue;
            }
            catch (const InvalidDateError& e)
            {
                std::cerr   << RED
                            << e.what()
                            << END
                            << std::endl;
                continue;
            }
            catch (const MissingValueError& e)
            {
                std::cerr   << RED
                            << e.what()
                            << END
                            << std::endl;
                continue;
            }
            catch (const NegativeValueError& e)
            {
                std::cerr   << RED
                            << e.what()
                            << END
                            << std::endl;
                continue;
            }
            catch (const ValueTooLargeError& e)
            {
                std::cerr   << RED
                            << e.what()
                            << END
                            << std::endl;
                continue;
            }
            catch (const BadInputError& e)
            {
                std::cerr   << RED
                            << e.what()
                            << END
                            << std::endl;
                continue;
            }
        }
    }
    catch (const MissingInfileError& e)
    {
        std::cerr   << RED
                    << e.what()
                    << END
                    << std::endl;
        std::cerr   << BLUE
                    << "[USAGE] : ./btc [input file name]"
                    << END
                    << std::endl;
        return (1);
    }
    catch (const OpenInfileError& e)
    {
        std::cerr   << RED
                    << e.what()
                    << END
                    << std::endl;
        return (1);
    }
    catch (const OpenDataBaseError& e)
    {
        std::cerr   << RED
                    << e.what()
                    << END
                    << std::endl;
        return (1);
    }
    catch (std::exception & e)
    {
        std::cerr << RED << e.what() << END << std::endl;
        return (1);
    }

    return (0);
}