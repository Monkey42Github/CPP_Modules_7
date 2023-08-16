#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

template< typename T >
class Array
{
    private:
        unsigned int    _size;
        T*              _array;

    public:
        Array() : _size(0) { _array = new T[0]; }
        Array(unsigned int n) : _size(n) { _array = new T[n]; }
        Array(Array const & src) : _size (src.n)
        {
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = src._array[i];
        }
        ~Array()
        {
            delete[] _array;
        }

        Array & operator=(Array const & rhs)
        {
            if (this != &rhs)
            {
                delete[] _array;
                _size = rhs.n;
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = rhs._array[i];
            }
        }

        T & operator[](unsigned int i) const
        {
            if (i >= _size)
                throw std::exception();
            return _array[i];
        }

        unsigned int size() const
        {
            return _size;
        }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& _array)
{
    for (unsigned int i(0); i < _array.size(); i++)
        out << _array[i] << " ";
    return out;
};

#endif