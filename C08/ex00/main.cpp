
#include "easyfind.hpp"
#include <algorithm>

int main(void)
{
    int     array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::list< int >    list(array, array + sizeof(array) / sizeof(int));

    easy_find(list, 10);

    return EXIT_SUCCESS;
}
