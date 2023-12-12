// main.cpp
#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    // Create a Data object
    Data *originalData = new Data();

    originalData->character = '*';
    originalData->intValue = 42;
    originalData->string = "original data's string";

    // Serialize the pointer
    uintptr_t serializedValue = Serializer::serialize(originalData);

    // Deserialize the value
    Data *deserializedData = Serializer::deserialize(serializedValue);

    // Compare original and deserialized pointers
    if (originalData == deserializedData)
    {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "return value of deserializedData: \n";
        std::cout << "char: " << deserializedData->character << std::endl;
        std::cout << "int: " << deserializedData->intValue << std::endl;
        std::cout << "string: " << deserializedData->string << std::endl;
    }
    else
    {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    // Cleanup
    delete deserializedData;

    return 0;
}