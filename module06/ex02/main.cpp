/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lil@stud4student.42nyon.fr       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:15:00 by llethuil          #+#    #+#             */
/*   Updated: 2022/09/06 44:41:21 by llethuil         ###   ########lyonlyo   */
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
    identify(*p);

    delete p;

    return (0);
}

Base*   generate(void)
{
    int n;

    n = rand() % 3 + 1;

    Base *p;

    switch (n)
    {
        case 1:
            p = new A();
            std::cout << "[The generate() function has generated a A class]" << std::endl;
            break;
        case 2:
            p = new B();
            std::cout << "[The generate() function has generated a B class]" << std::endl;
            break;
        case 3:
            p = new C();
            std::cout << "[The generate() function has generated a C class]" << std::endl;
            break;
        default:
            p = NULL;
            break;
    }
    return (p);
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "The identify(Base* p) function recognize the A class !" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "The identify(Base* p) function recognize the B class !" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "The identify(Base* p) function recognize the C class !" << std::endl;
    return ;
}

void    identify(Base& p)
 {
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "The identify(Base& p) function recognize the A class !" << std::endl;
    }
    catch(const std::exception& e) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "The identify(Base& p) function recognize the B class !" << std::endl;
    }
    catch(const std::exception& e){}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "The identify(Base& p) function recognize the C class !" << std::endl;
    }
    catch(const std::exception& e) {}

    return ;
 }