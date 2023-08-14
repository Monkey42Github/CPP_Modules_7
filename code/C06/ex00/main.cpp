#include "Convert.hpp"

int main(int ac, char ** av)
{
    if ( ac != 2 )
    {
        std::cout << "Number off parms must be 1" << std::endl;
        return 1 ;
    }
    
    ScalarConverter convert;
    convert.set_para(av[1]);
    convert.convert();
 
    std::cout << convert;
  
    return 0;
}