#ifndef SERIALISATION_HPP
# define SERIALISATION_HPP

#include <iostream>
#include <cstdlib>


struct Data
{
    int value;
    Data(int v) : value(v) {}
};


class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr)
        {
            return reinterpret_cast < uintptr_t > (ptr);
        }
        static Data* deserialize(uintptr_t raw)
        {
            return reinterpret_cast<Data*>(raw);
        }

};




#endif