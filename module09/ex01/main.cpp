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
        std::cerr   << RED
                    << "[ERROR] : "
                    << e.what()
                    << END
                    << std::endl;
        std::cerr   << BLUE
                    << "[USAGE] : ./RPN \"expression\""
                    << END
                    << std::endl;
        return (1);
    }
    catch (const InvalidTokenError& e)
    {
        std::cerr   << RED
                    << "[ERROR] : "
                    << e.what()
                    << END
                    << std::endl;
        return (1);
    }
    catch (const IncompleteExpressionError& e)
    {
        std::cerr   << RED
                    << "[ERROR] : "
                    << e.what()
                    << END
                    << std::endl;
        return (1);
    }
    catch (const DivByZeroError& e)
    { 
        std::cerr   << RED
                    << "[ERROR] : "
                    << e.what()
                    << END
                    << std::endl;
        return (1);
    }
    catch (const std::runtime_error& e)
    {
        std::cerr   << RED
                    << "[ERROR] : "
                    << e.what()
                    << END
                    << std::endl;
        return (1);
    }
    
    return (0);
}
