
#include "easyfind.hpp"
#include <algorithm>

int main(void)
{

    int     arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::list< int >    list(arr, arr + sizeof(arr) / sizeof(int));

    easy_find(list, 10);

    return EXIT_SUCCESS;

}
