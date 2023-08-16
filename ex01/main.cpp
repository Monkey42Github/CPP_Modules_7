#include "iter.hpp"


template <typename T>
void    print(T &i)
{
    std::cout << i << std::endl;
}

int main(void)
{
    int tab1[] = { 1, 2, 3 };
    std::cout << "tab 1 :" << std::endl;
    iter(tab1, 3, &print);


    double tab2[] = { 1.1, 2.2, 3.3 };
    std::cout << "\ntab 2 :" << std::endl;
    iter(tab2, 3, &print);


    char tab3[] = { 'a', 'b', 'c' };
    std::cout << "\ntab 3 :" << std::endl;
    iter(tab3, 3, &print);


    std::string tab4[] = { "one", "two", "three" };
    std::cout << "\ntab 4 :" << std::endl;
    iter(tab4, 3, &print);

    return 0;
}
