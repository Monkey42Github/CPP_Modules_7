#include "Array.hpp"


int main( void )
{
    Array<float> test;
    Array<int> intArray(5);
    Array<int> intArray2(10);

    for (unsigned int i = 0; i < 5; i++)
        intArray[i] = i * 2;

    std::cout << "Int Array 1: " << intArray << std::endl;

    intArray2 = intArray;

    std::cout << "int Array 2: " << intArray2 << std::endl;

    try {
        std::cout << "Accessing a valid index: " << intArray[5] << std::endl;
        std::cout << "Accessing an invalid index: " << intArray[5] << std::endl;
    } catch ( Array::errorException& e ) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return ( 0 );
}