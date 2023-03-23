/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:18:45 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/23 10:01:59 by llethuil         ###   ########.fr       */
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
    catch (const std::exception& e)
    {
        pmergeMe.printCaughtError(e);
        pmergeMe.printUsage();
        return (1);
    }

    return (0);
}
