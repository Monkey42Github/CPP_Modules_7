#include "serialisation.hpp"



int main(void)
{
    Data dataObj(42);

    uintptr_t serialized = Serializer::serialize(&dataObj);
    Data* deserialized = Serializer::deserialize(serialized);

    if (deserialized == &dataObj)
        std::cout << "Serialization and deserialization successful!" << std::endl;
    else
        std::cout << "Serialization and deserialization failed!" << std::endl;

    return 0;
}