/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:18:45 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/22 13:37:40 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av)
{
    PmergeMe pmergeMe;

    try
    {
        pmergeMe.parseArguments(ac, av);
        pmergeMe.process();
        pmergeMe.printResults();
    }
    catch (const MissingArgumentError& e)
    {
        std::cerr   << RED << e.what() << END
                    << std::endl
                    << BLUE << "[USAGE]\t\t\t\t: ./PmergeMe [positive int] [positive int] [positive int]..." << END
                    << std::endl
                    << std::endl;
        return (1);
    }
    catch (const NonIntError& e)
    {
        std::cerr   << RED << e.what() << END
                    << std::endl
                    << BLUE << "[USAGE]\t\t\t\t: ./PmergeMe [positive int] [positive int] [positive int]..." << END
                    << std::endl
                    << std::endl;
        return (1);
    }
    catch (const NegativeIntError& e)
    {
        std::cerr   << RED << e.what() << END
                    << std::endl
                    << BLUE << "[USAGE]\t\t\t\t: ./PmergeMe [positive int] [positive int] [positive int]..." << END
                    << std::endl
                    << std::endl;
        return (1);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << END << std::endl;
        return (1);
    }

    return (0);
}
