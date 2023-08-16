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


const std::list<int>* Span::getList(void) const
{
    return &_list;
}



void Span::addNumber(int N)
{
    if (_list.size() > _N)
        throw std::out_of_range("Error: Out of the list");
    _list.push_back(N);
}

void  Span::addNumbers(std::list<int>   addlist)
{
    if(_list.size() + addlist.size() > _N)
        throw std::out_of_range("Error: N too small");

    for (std::list<int>::const_iterator i = addlist.begin(); i != addlist.end(); ++i)
        _list.push_back(*i);
}


unsigned int Span::longestSpan() const
{
    if (_list.size() <= 1)
        throw std::logic_error("Error: Not enough number in the list");

    int max = *std::max_element(_list.begin(), _list.end());
    int min = *std::min_element(_list.begin(), _list.end());

    return static_cast<unsigned int> (max - min);
}

unsigned int Span::shortestSpan() const
{
    if (_list.size() <= 1)
        throw std::logic_error("Error: Not enough numbers in the list");

    unsigned int minDistance = std::numeric_limits<unsigned int>::max();
    std::list<int>::const_iterator i = _list.begin();
    std::list<int>::const_iterator next = i;
    ++next;

    for (; next != _list.end(); ++i, ++next) {
        unsigned int distance = static_cast<unsigned int>(*next) - static_cast<unsigned int>(*i);
        minDistance = std::min(minDistance, distance);
    }

    return minDistance;
}

std::ostream& operator<<(std::ostream& o, const Span& span)
{
    for (std::list<int>::const_iterator i = span.getList()->begin(); i != span.getList()->end(); ++i)
        o << *i << std::endl;
    return o;
}
