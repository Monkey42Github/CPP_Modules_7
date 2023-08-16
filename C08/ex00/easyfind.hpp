
#include<iostream>
#include <algorithm>
#include <list>
#include <vector>

template <typename T>
void easy_find(T& container, int value)
{
    if (std::find(container.begin(), container.end(), value) != container.end())
        std::cout << "value found !" << std::endl;
    else
        std::cout << "Not value found" << std::endl;
}

