#include "Convert.hpp"

ScalarConverter::ScalarConverter(void)
{
    this->_c = '\0';
    this->_i = 0;
    this->_f = 0.0f;
    this->_d = 0.0;
    return;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
    *this = src;
    return;
}

ScalarConverter::~ScalarConverter(void){ return; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    if(this != &rhs)
    {
        this->_i = rhs.get_int();
        this->_f = rhs.get_float();
        this->_c = rhs.get_char();
        this->_d = rhs.get_double();
    }
    return *this;
}

char ScalarConverter::get_char(void) const
{
    return this->_c;
}

int ScalarConverter::get_int(void) const
{
    return this->_i;
}

float ScalarConverter::get_float(void) const
{
    return this->_f;
}

std::string ScalarConverter::get_para(void) const 
{
    return this->_para;
}

double ScalarConverter::get_double(void) const
{
    return this->_d;
}


void    ScalarConverter::set_char(char c) 
{
    this->_c = c;
}

void    ScalarConverter::set_int(char i)
{
    this->_i = i;
}

void    ScalarConverter::set_float(char f) 
{
    this->_f = f;
}

void    ScalarConverter::set_double(char d) 
{
    this->_d = d;
}

void ScalarConverter::set_para(std::string para) 
{
    this->_para = para;
}

bool is_int(const std::string& str) {
    if (str.empty())
        return false;

    size_t start = 0;
    if (str[start] == '-' || str[start] == '+')
        start++;

    for (size_t i = start; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool is_float(const std::string& str)
{ 
    int count = 0;
    int startIndex = 0;

    if (str.find('.') == std::string::npos || str.back() != 'f' ||
        str.find('.') == 0 || str.find('.') == str.length() - 1) 
        return false;

    if (str[startIndex] == '-' || str[startIndex] == '+')
        startIndex++;
    for (int i = startIndex; i < static_cast<int>(str.length() - 1); i++)
    {
        if (str[i] == '.')
            count++;
        if ((!std::isdigit(str[i]) && str[i] != '.') || count > 1)
            return false;
    }
    return true;
}


bool is_double(const std::string& str)
{
    size_t i = 0;
    bool hasDecimal = false;

    if (str[i] == '-' || str[i] == '+')
        i++;
    while (i < str.length() && (std::isdigit(str[i]) || str[i] == '.'))
    {
        if (str[i] == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        i++;
    }
    return i == str.length() && hasDecimal;
}

bool    is_pseudo_litteraux(const std::string str , bool prob) 
{
        if (prob || 
        str.compare("nan") == 0 || str.compare("nanf") == 0 ||
        str.compare("+inf") == 0 || str.compare("+inff") == 0 ||
        str.compare("-inf") == 0 || str.compare("-inff") == 0)
        return true;
    return false;
}

void    ScalarConverter::set_type(void) 
{
    if (_para.length() == 1 && std::isalpha(_para[0]) && std::isprint(_para[0])) 
        _type = CHAR;
    else if (is_int(_para))
        _type = INT;
    else if (is_float(_para))
        _type = FLOAT;
    else if (is_double(_para)) 
        _type = DOUBLE;
    else if (is_pseudo_litteraux(_para, _prob))
        _type = LITERALS;
    else 
        _type = NONE;
}

bool    ScalarConverter::is_prob(void) 
{
    this->set_type();
    try
    {
        if (_type == INT)
            _i = std::stoi( _para );
        else if ( _type == FLOAT ) 
            _f = std::stof( _para );
         else if ( _type == DOUBLE ) 
            _d = std::stod( _para );
    }
    catch (std::exception& e)
    {
        _prob = true;
        return true;
    }
    return false;
}

void    ScalarConverter::convert(void) 
{
    if (is_prob())
        return;
    
    _prob = false;
    switch (_type) 
    {
        case CHAR:
            _c = _para[0];
            _i = static_cast< int >(_c);
            _f = static_cast< float >(_c);
            _d = static_cast< double >(_c);
            break;
        case INT:
            _i = std::stoi(_para);
            _c = static_cast< char >(_i);
            _f = static_cast< float >(_i);
            _d = static_cast< double >(_i);
            break;
        case FLOAT:
            _f = std::stof(_para);
            _c = static_cast< char >(_f);
            _i = static_cast< int >(_f);
            _d = static_cast< double >(_f);
            break;
        case DOUBLE:
            _d = std::stod(_para);
            _c = static_cast< char >(_f);
            _i = static_cast< int >(_d);
            _f = static_cast< float >(_d);
            break;
        default:
            break;
    }
}

void    ScalarConverter::print_char(void) const
{
    if (_type == LITERALS || (!std::isprint(_i) && (_i >= 127)))
        std::cout << "Impossible" << std::endl;
    else if (!std::isprint(this->_i))
        std::cout << "None displayable" << std::endl;
    else
        std::cout << "'" << get_char() << "'" << std::endl;
}

void    ScalarConverter::print_int(void) const
{
    if (_type == LITERALS || (!std::isprint(_i) && (_i >= 127)))
        std::cout << "Impossible" << std::endl;
    else
        std::cout << get_int() << std::endl;
}

void    ScalarConverter::print_float( void ) const
{
    if  (_para.compare("nan") == 0 || _para.compare("nanf") == 0)
        std::cout << "nanf" << std::endl;
    else if (_para.compare("+inff") == 0 || _para.compare("+inf") == 0)
        std::cout << "+inff" << std::endl;
    else if (_para.compare("-inff") == 0 || _para.compare("-inf") == 0)
        std::cout << "-inff" << std::endl;
    else if (_prob)
        std::cout << "Impossible" << std::endl;
    else
    {
        if (_f - static_cast< int > (_f) == 0)
            std::cout << _f << ".0f" << std::endl;
        else
            std::cout << get_float() << "f" << std::endl;
    }
}

void    ScalarConverter::print_double(void) const
{
    if (_para.compare("nan") == 0 || _para.compare("nanf") == 0)
        std::cout << "nan" << std::endl;
    else if (_para.compare("+inff") == 0 || _para.compare("+inf") == 0)
        std::cout << "+inf" << std::endl;
    else if (_para.compare("-inff") == 0 || _para.compare("-inf") == 0)
        std::cout << "-inf" << std::endl;
    else if (_prob)
        std::cout << "Impossible" << std::endl;
    else
    {
        if (_d - static_cast< int > (_d) == 0)
            std::cout << _d << ".0" << std::endl;
        else
            std::cout << get_double() << "f" << std::endl;
    }
}

std::ostream&    operator<<(std::ostream& out, const ScalarConverter& rhs)
{
    out << "char: "; rhs.print_char();
    out << "int: "; rhs.print_int();
    out << "float: "; rhs.print_float();
    out << "double: "; rhs.print_double();
    return out;
}
