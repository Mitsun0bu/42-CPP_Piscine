/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:18:45 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/21 11:22:56 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av)
{
    try
    {
        PmergeMe pmergeMe(ac, av);
        pmergeMe.process();
        pmergeMe.printResults();
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
