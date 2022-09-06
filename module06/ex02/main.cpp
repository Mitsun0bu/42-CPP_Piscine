/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:15:00 by llethuil          #+#    #+#             */
/*   Updated: 2022/09/06 17:45:38 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

int main (void)
{
    srand (time(NULL));
    Base*   p;

    std::cout << std::endl;
    p = generate();
    std::cout << std::endl;

    identify(p);
    std::cout << std::endl;
    if (p)
        identify(*p);

    delete p;

    return (0);
}

Base*   generate(void)
{
    int n;

    n = rand() % 3 + 1;

    Base *p;

    std::cout << GREEN << "[TEST - generate() function]" << END << std::endl;

    switch (n)
    {
        case 1:
            p = new A();
            std::cout << "The generate() function has generated a A class" << std::endl;
            break;
        case 2:
            p = new B();
            std::cout << "The generate() function has generated a B class" << std::endl;
            break;
        case 3:
            p = new C();
            std::cout << "The generate() function has generated a C class" << std::endl;
            break;
        default:
            p = NULL;
            break;
    }
    return (p);
}

void    identify(Base* p)
{
    std::cout << GREEN << "[TEST - identify(Base* p) function]" << END << std::endl;


    if (dynamic_cast<A*>(p))
        std::cout << "A class has been recognized !" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B class has been recognized !" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C class has been recognized !" << std::endl;
    else
        std::cout << "Error ! Dynamic cast return is NULL. " << std::endl;

    return ;
}

void    identify(Base& p)
 {
    std::cout << GREEN << "[TEST - identify(Base& p) function]" << END << std::endl;

    try
    {
        static_cast <void> (dynamic_cast <A&> (p));
        std::cout << "A class has been recognized !" << std::endl;
    }
    catch(const std::bad_cast& e) {}

    try
    {
        static_cast <void> (dynamic_cast<B&>(p));
        std::cout << "B class has been recognized !" << std::endl;
    }
    catch(const std::bad_cast& e){}

    try
    {
        static_cast <void> (dynamic_cast<C&>(p));
        std::cout << "C class has been recognized !" << std::endl;
    }
    catch(const std::bad_cast& e) {}

    return ;
 }