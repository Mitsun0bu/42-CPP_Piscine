#include "RPN.hpp"

int main(int ac, char* av[])
{
    if (ac != 2)
    {
        std::cerr << BLUE << "[USAGE] : ./RPN \"expression\"" << END << std::endl;
        return (1);
    }
    return (handleExpression(av[1]));
}
