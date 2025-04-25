#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(T const& element) {
    std::cout << element << " ";
}

template <typename T>
void doubleValue(T& element) {
    element *= 2;
}

template <typename T>
void addOne(T& element) {
    element += 1;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = 5;
    
    std::cout << "Int array original values: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;
    
    iter(intArray, intArrayLength, doubleValue<int>);
    
    std::cout << "Int array after doubling: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;
    
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    size_t floatArrayLength = 5;
    
    std::cout << "Float array original values: ";
    iter(floatArray, floatArrayLength, printElement<float>);
    std::cout << std::endl;
    
    iter(floatArray, floatArrayLength, addOne<float>);
    
    std::cout << "Float array after adding 1: ";
    iter(floatArray, floatArrayLength, printElement<float>);
    std::cout << std::endl;
    
    std::string stringArray[] = {"Hello", "World", "Template", "Function", "Test"};
    size_t stringArrayLength = 5;
    
    std::cout << "String array values: ";
    iter(stringArray, stringArrayLength, printElement<std::string>);
    std::cout << std::endl;
    
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArrayLength = 5;
    
    std::cout << "Char array original values: ";
    iter(charArray, charArrayLength, printElement<char>);
    std::cout << std::endl;
    
    iter(charArray, charArrayLength, addOne<char>);
    
    std::cout << "Char array after adding 1: ";
    iter(charArray, charArrayLength, printElement<char>);
    std::cout << std::endl;
    
    return 0;
}
