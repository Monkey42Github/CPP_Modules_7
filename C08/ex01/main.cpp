#include"Span.hpp"

int main(void)
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;

    Span mySpan(5);
    std::list<int> newElems;
    newElems.push_back(10);
    newElems.push_back(20);
    newElems.push_back(30);
    newElems.push_back(40);
    newElems.push_back(50);
    mySpan.addNumbers(newElems);
    std::cout << mySpan << std::endl;
    std::cout << mySpan.shortestSpan() << std::endl;
    return 0;
}
