# ifndef SPAN_HPP
# define SPAN_HPP


#include <iostream>
#include <exception>
#include <list>
#include <vector>
#include <algorithm>
#include <limits>

class Span 
{
    private:
        std::list<int>  _list;
        unsigned int    _N;

    public:
        Span(void);
        Span(unsigned int);
        Span(const Span&);
        ~Span(void);

        Span&   operator=(const Span&);

        const std::list<int>* getList(void) const;
        
        void            addNumber(int n);
        void            addNumbers(std::list<int>  addlist);

        unsigned int    longestSpan(void) const;
        unsigned int    shortestSpan(void) const;
};

std::ostream& operator<<( std::ostream&, const Span& );

#endif