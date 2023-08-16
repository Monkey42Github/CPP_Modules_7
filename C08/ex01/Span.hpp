
#include <iostream>
#include <list>


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
        
        void            addNumber(int);
        unsigned int    longestSpan(void) const;
        unsigned int    shortestSpan(void) const;
};

std::ostream& operator<<( std::ostream&, const Span& );