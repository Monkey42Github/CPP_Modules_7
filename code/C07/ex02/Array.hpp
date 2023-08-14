
#include <iostream>

template < typename T >
class Array {

    private:
        T*              _array;
        unsigned int    _size;
        
    public:
        Array(void) : _array(new T()), _size(0) { };
        Array(unsigned int n) : _array(new T[n]), _size(n) { };
        Array(const Array& rhs) : _array(new T[rhs.size()]), _size(rhs.size())
        {
            for (unsigned int i(0); i < _size; i++)
                _array[i] = rhs._array[i];
        };
        ~Array(void) { delete [] _array; }

        Array& opperator=(const Array& rhs)
        {
            if(this != &rhs)
            {
                delate [] _array;
                _array = new T[rhs.size()];
                _size = rhs._size;
                for (unsigned int i(0); i < _size; i++)
                    _array[i] = rhs.array[i];
            }
            return *this;
        }
        
        T& operator[](unsigned int i) const
        {
            if (num < 0)
				throw Array::errorException();
            else if (i >= _size)
                throw errorException();
            return _arr[i];
        }

        class errorException : public std::exception
        {
            public:
                virtual const char* what() const trow()
                {
                    return("Index is exceeded";);
                }
        };
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& array)
{
    for (unsigned int i(0); i < array.size(); i++)
        out << array[i] << " ";
    return out;
}
