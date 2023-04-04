/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:33:50 by llethuil          #+#    #+#             */
/*   Updated: 2023/04/04 11:33:52 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char* av[])
{
    RPN                 rpnCalculator;

    try
    {
        if (ac != 2)
            throw (MissingArgumentError());
        const std::string   expression = av[1];
        rpnCalculator.parseArgument(expression);
        rpnCalculator.process(expression);
        rpnCalculator.printResult();
    }
    catch (const MissingArgumentError& e)
    {
        rpnCalculator.printCaughtError(e);
        rpnCalculator.printUsage();
        return (1);
    }
    catch (const std::runtime_error& e)
    {
        rpnCalculator.printCaughtError(e);
        return (1);
    }
    
    return (0);
}
