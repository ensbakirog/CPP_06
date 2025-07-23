#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
    Data data;
    data.name = "TestData";
    data.value = 42;

    std::cout << "Original Data: name = " << data.name << ", value = " << data.value << std::endl;
    std::cout << "Original pointer: " << &data << std::endl;

    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "Serialized value: " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer: " << deserialized << std::endl;
    std::cout << "Deserialized Data: name = " << deserialized->name << ", value = " << deserialized->value << std::endl;

    if (deserialized == &data) {
        std::cout << "Success: Deserialized pointer matches original pointer!" << std::endl;
    } else {
        std::cerr << "Error: Deserialized pointer does not match original pointer!" << std::endl;
    }

    return 0;
}