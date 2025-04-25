#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data originalData(42, "Test Data", 3.14159);
    
    std::cout << "Original Data object:" << std::endl;
    std::cout << "Address: " << &originalData << std::endl;
    std::cout << "ID: " << originalData.id << std::endl;
    std::cout << "Name: " << originalData.name << std::endl;
    std::cout << "Value: " << originalData.value << std::endl;
    std::cout << std::endl;
    
    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "Serialized value (uintptr_t): " << serialized << std::endl;
    std::cout << std::endl;
    
    Data* deserialized = Serializer::deserialize(serialized);
    
    std::cout << "Deserialized Data object:" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "ID: " << deserialized->id << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Value: " << deserialized->value << std::endl;
    std::cout << std::endl;
    
    std::cout << "Are the addresses equal? " 
              << ((&originalData == deserialized) ? "YES" : "NO") << std::endl;
    
    return 0;
}
