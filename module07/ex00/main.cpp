/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:39:15 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/08 10:08:38 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "whatever.hpp"

int main(void)
{
    int a = 2;
    int b = 3;

    std::cout << std::endl;
    ::swap<int>( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min<int>( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max<int>( a, b ) << std::endl;
    std::cout << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap<std::string>(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min<std::string>( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max<std::string>( c, d ) << std::endl;

    return 0;
}
