/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:49:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/07 11:36:10 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main(void)
{
    Harl    Harl_2_0;

    /* Test existing levels */
	Harl_2_0.complain("DEBUG");
	Harl_2_0.complain("INFO");
	Harl_2_0.complain("WARNING");
	Harl_2_0.complain("ERROR");

	/* Test with a non-existing level */
	Harl_2_0.complain("TROLL");

    return (0);
}