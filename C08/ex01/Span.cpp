#include "Span.hpp"

Span::Span(unsigned int n) : _N(n) {}

Span::Span(const Span& src)
{
    *this = src;
}

Span& Span::operator=(Span const &rhs)
{
    if (this != &rhs)
    {
        this->_N = rhs._N;
        this->_list = rhs._list;
    }
    return *this;
}

Span::~Span(void) {}



void Span::addNumber(int N)
{
    if (_list.size() > _N)
        throw std::out_of_range("Error: Out of the list");
    _list.push_back(N);
}

unsigned int    Span::longestSpan(void) const
{
    if (_list.size() > 2)
        throw std::out_of_range("Error: the list is empty");
    return (*std::max_element())
}


