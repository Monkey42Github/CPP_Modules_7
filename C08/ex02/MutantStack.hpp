#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include<iostream>
#include<stack>

template<typename T>
class MutantStack: public std::stack<T>
{
    public:
        MutantStack<T>(void) { };
        MutantStack<T>(const MutantStack<T> &src) { *this = src;};
        ~MutantStack<T>(void) {};

        MutantStack<T> &operator=(const MutantStack<T> &rhs)
        {
            (void)rhs;
            return *this;
        }

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }

};

#endif