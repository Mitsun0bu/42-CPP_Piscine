/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:00:20 by llethuil          #+#    #+#             */
/*   Updated: 2022/08/03 13:31:29 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

# include "Converter.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTORS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

Converter::Converter(void)
{
    std::cout << std::endl << BLUE << "[CONSTRUCTOR] : " << END
			  << "Converter has been created." << std::endl
              << std::endl;
	return ;
}

Converter::Converter(std::string arg) : _arg(arg)
{
    std::cout << std::endl << BLUE << "[CONSTRUCTOR] : " << END
			  << "Converter has been created." << std::endl
              << std::endl;
	return ;
}

Converter::Converter(Converter& src)
{
    std::cout << ORANGE << "[COPY CONSTRUCTOR] : " << END
    << "A Converter has been duplicated !" << std::endl
    << std::endl;
    *this = src;
    return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ OPERATOR OVERLOAD ~~~                         */
/*                                                                            */
/* ************************************************************************** */

Converter& Converter::operator=(Converter const & src)
{
    this->_arg = src._arg;
    return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                          ~~~ MEMBER FUNCTIONS ~~~                          */
/*                                                                            */
/* ************************************************************************** */

/* Functions to detect the type of the literal passed as parameter */

bool Converter::argIsChar()
{
    if (this->_arg.length() == 1 && isalpha(_arg[0]) > 0)
        return true;
    return false;
}

bool Converter::argIsInt()
{
    for (size_t i = 0; i < this->_arg.length(); i++)
    {
        if (i == 0 && _arg[i] == '-')
            i ++;
        else if (isdigit(_arg[i]) == false)
            return false;
    }    
    return true;
}

bool Converter::argIsFloat()
{
    bool    dot = false;
    bool    f = false;

    for (size_t i = 0; i < this->_arg.length(); i++)
    {
        if (i == 0 && _arg[i] == '-')
            i ++;
        else if (i != 0 && i != this->_arg.length() - 1 && _arg[i] == '.')
        {
            if (dot == true)
                return false;
            dot = true;
        }
        else if (i == this->_arg.length() - 1 && _arg[i] == 'f' && f == false)
            f = true;
        else if (isdigit(_arg[i]) == false)
            return false;
    }
    if (this->_arg.length() < 4 || dot != true || f != true)
        return false;
    return true;
}

bool Converter::argIsDouble()
{
    bool    dot = false;

    for (size_t i = 0; i < this->_arg.length(); i++)
    {
        if (i == 0 && _arg[i] == '-')
            i ++;
        else if (i != 0 && i != this->_arg.length() - 1 && _arg[i] == '.')
        {
            if (dot == true)
                return false;
            dot = true;
        }
        else if (isdigit(_arg[i]) == false)
            return false;
    }
    if (this->_arg.length() < 3 || dot != true)
        return false; 
    return true;
}

/* Functions to handle char arguments */

void Converter::handleChar()
{
	this->argToChar();

    this->printCharValue();

    this->charToInt();
    this->charToFloat();
    this->charToDouble();

    return ;
}

void Converter::argToChar()
{
    const char    *temp = this->_arg.c_str();

    this->_char = temp[0];

    return ;
}

void Converter::printCharValue()
{
    std::cout << "char\t:\t'"
              << this->_char
              << "'" 
              << std::endl;
    return ;
}

void Converter::charToInt()
{
    this->_int = static_cast <int> (this->_char);

    std::cout << "int\t:\t" << this->_int << std::endl;

    return ;
}

void Converter::charToFloat()
{
    std::cout << std::fixed;
    std::cout.precision(1);

    this->_float = static_cast <float> (this->_char);

    std::cout << "float\t:\t" << this->_float << "f" << std::endl;

    return ;
}

void Converter::charToDouble()
{
    this->_double = static_cast <double> (this->_char);

    std::cout << "double\t:\t" << this->_double << std::endl;

    return ;
}

/* Functions to handle int arguments */

void Converter::handleInt()
{
    this->argToInt();

    try
    {
        this->intToChar();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->printIntValue();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        this->intToFloat();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        this->intToDouble();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return ;
}

void Converter::argToInt()
{
    std::istringstream(this->_arg) >> this->_int;

    return ;
}

void Converter::intToChar()
{
    this->_char = static_cast <char> (this->_int);

    std::cout << "char\t:\t";

    if (this->_arg != "-2147483648" && this->_int == std::numeric_limits<int>::min())
        throw ImpossibleException();
    else if (this->_arg != "2147483647" && this->_int == std::numeric_limits<int>::max())
        throw ImpossibleException();
    else if ((this->_int >=0 && this->_int < 32) || (this->_int > 126 && this->_int <= 256))
        throw NonDisplayableException();
    else if ((this->_int < 0 || this->_int > 256))
        throw ImpossibleException();
    else
        std::cout << "'" << this->_char << "'" << std::endl;

    return ;
}

void Converter::printIntValue()
{
    std::cout << "int\t:\t";

    if (this->_arg != "-2147483648" && this->_int == std::numeric_limits<int>::min())
        throw UnderflowException();
    else if (this->_arg != "2147483647" && this->_int == std::numeric_limits<int>::max())
        throw OverflowException();
    else
        std::cout << this->_int << std::endl;

    return ;
}

void Converter::intToFloat()
{
    std::cout << std::fixed;
    std::cout.precision(1);

    this->_float = static_cast <float> (this->_int);

    std::cout << "float\t:\t";

    if (this->_arg != "-2147483648" && this->_int == std::numeric_limits<int>::min())
        throw ImpossibleException();
    else if (this->_arg != "2147483647" && this->_int == std::numeric_limits<int>::max())
        throw ImpossibleException();
    else
        std::cout << this->_float << "f" << std::endl;

    return ;
}

void Converter::intToDouble()
{
    std::cout << std::fixed;
    std::cout.precision(1);
    
    this->_double = static_cast <double> (this->_int);

    std::cout << "double\t:\t";

    if (this->_arg != "-2147483648" && this->_int == std::numeric_limits<int>::min())
        throw ImpossibleException();
    else if (this->_arg != "2147483647" && this->_int == std::numeric_limits<int>::max())
        throw ImpossibleException();
    else
        std::cout << this->_double << std::endl;
    
    return ;
}


/* Functions to handle float arguments */

void Converter::handleFloat()
{
    this->argToFloat();

    try
    {
        this->floatToChar();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->floatToInt();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->printFloatValue();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        this->floatToDouble();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return ;
}

void Converter::argToFloat()
{
    double  temp = atof(_arg.c_str());
    this->_float = static_cast <float> (temp);

    return ;
}

void Converter::floatToChar()
{
    this->_char = static_cast <char> (this->_float);

    float   whole = floor(this->_float);
    float   frac = this->_float - whole;

    std::cout << "char\t:\t";

    if (frac != 0)
        throw ImpossibleException();
    else if (((this->_float >= 0 && this->_float < 32) || (this->_float > 126 && this->_float < 256)))
        throw NonDisplayableException();
    else if ((this->_float < 0 || this->_float >= 256))
        throw ImpossibleException();
    else
        std::cout << "'" << this->_char << "'" << std::endl;

    return ;
}

void Converter::floatToInt()
{
    this->_int = static_cast <int> (this->_float);
    
    std::cout << "int\t:\t";

    if (this->_int == std::numeric_limits<int>::min() || this->_int == std::numeric_limits<int>::max())
        throw ImpossibleException();
    else
        std::cout << this->_int << std::endl;

    return ;
}

void Converter::printFloatValue()
{
    std::cout << std::fixed;
    std::cout.precision(1);

    std::cout << "float\t:\t" << this->_float << "f" << std::endl;

    return ;
}

void Converter::floatToDouble()
{
    std::cout << std::fixed;
    std::cout.precision(1);

    this->_double = static_cast <double> (this->_float);
    std::cout << "double\t:\t" << this->_double << std::endl;
    
    return ;
}

/* Functions to convert double argument to other types */

void Converter::handleDouble()
{
    this->argToDouble();

    try
    {
        this->doubleToChar();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->doubleToInt();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->doubleToFloat();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->printDoubleValue();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return ;
}

void Converter::argToDouble()
{
    this->_double = atof(_arg.c_str());

    return ;
}

void Converter::doubleToChar()
{
    this->_char = static_cast <char> (this->_double);
    
    double   whole = floor(this->_double);
    double   frac = this->_double - whole;

    std::cout << "char\t:\t";

    if (frac != 0)
        throw ImpossibleException();
    else if (((this->_double >= 0 && this->_double < 32) || (this->_double > 126 && this->_double < 256)))
        throw NonDisplayableException();
    else if ((this->_double < 0 || this->_double >= 256))
        throw ImpossibleException();
    else
        std::cout << "'" << this->_char << "'" << std::endl;

    return ;
}

void Converter::doubleToInt()
{
    this->_int = static_cast <int> (this->_double);
    
    std::cout << "int\t:\t";
    
    if (this->_int == std::numeric_limits<int>::min() || this->_int == std::numeric_limits<int>::max())
        throw ImpossibleException();
    else
        std::cout << this->_int << std::endl;

    return ;
}

void Converter::doubleToFloat()
{
    std::cout << std::fixed;
    std::cout.precision(1);

    this->_float = static_cast <float> (this->_double);
    
    std::cout << "float\t:\t";

    if (this->_float == std::numeric_limits<float>::min() || this->_float == std::numeric_limits<float>::max())
        throw ImpossibleException();
    else
        std::cout << this->_float << "f" << std::endl;

    return ;
}

void Converter::printDoubleValue()
{
    std::cout << std::fixed;
    std::cout.precision(1);
    
    std::cout << "double\t:\t" << this->_double << std::endl;

    return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ EXCEPTIONS ~~~                            */
/*                                                                            */
/* ************************************************************************** */

const char*			Converter::OverflowException::what() const throw()
{
    return ("overflow");
}

const char*			Converter::UnderflowException::what() const throw()
{
    return ("underflow");
}

const char*			Converter::NonDisplayableException::what() const throw()
{
	return ("non displayable");
}

const char*			Converter::ImpossibleException::what() const throw()
{
	return ("impossible");
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

Converter::~Converter(void)
{
    std::cout << std::endl << PURPLE << "[DESTRUCTOR] : " << END
			  << "Converter has been destructed." << std::endl
              << std::endl;
	return ;
}