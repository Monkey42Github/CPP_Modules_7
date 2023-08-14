#include "template.hpp"

int main( void )
{
    int a = 2;
    int b = 3;

    swap( a, b );

    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;

    std::cout << "min : " << min(a, b) << std::endl;
    std::cout << "max : " << max(a, b) << std::endl;

    return 0;
}


