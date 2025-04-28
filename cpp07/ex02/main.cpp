#include <iostream>
#include <string>
#include "Array.hpp"

template <typename T>
void displayArray(const Array<T>& arr, const std::string& name) {
    std::cout << name << " (size " << arr.size() << "): ";
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i == arr.size() - 1)
            break;
        std::cout << ", ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << std::endl << "===== Default Constructor Test =====" << std::endl;
    {
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;
        
        try {
            std::cout << "Trying to access element 0: ";
            std::cout << emptyArray[0] << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    
    std::cout << std::endl << "===== Parameterized Constructor Test =====" << std::endl;
    {
        Array<int> intArray(5);
        displayArray(intArray, "Int array after creation");
        
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 10;
        }
        displayArray(intArray, "Int array after modification");
    }
    
    std::cout << std::endl << "===== Different Types Test =====" << std::endl;
    {
        Array<char> charArray(4);
        for (unsigned int i = 0; i < charArray.size(); i++) {
            charArray[i] = 'A' + i;
        }
        displayArray(charArray, "Char array");
        
        Array<std::string> stringArray(3);
        stringArray[0] = "Hello";
        stringArray[1] = "CPP";
        stringArray[2] = "Module 07";
        displayArray(stringArray, "String array");
    }
    
    std::cout << std::endl << "===== Copy Constructor and Assignment Operator Test =====" << std::endl;

    Array<int> original(4);
    for (unsigned int i = 0; i < original.size(); i++) {
        original[i] = i + 1;
    }
    displayArray(original, "Original array");
    
    Array<int> copyConstructed(original);
    displayArray(copyConstructed, "Copy constructed array");
    
    Array<int> assigned;
    assigned = original;  
    displayArray(assigned, "Assigned array");
    
    std::cout << "Modifying original array..." << std::endl;
    for (unsigned int i = 0; i < original.size(); i++) {
        original[i] = 100 + i;
    }
    
    displayArray(original, "Modified original");
    displayArray(copyConstructed, "Copy constructed (should be unchanged)");
    displayArray(assigned, "Assigned (should be unchanged)");
    
    std::cout << std::endl << "===== Exception Handling Test =====" << std::endl;
    
    Array<int> arr(3);
    
    std::cout << "Array size: " << arr.size() << std::endl;
    
    try {
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        std::cout << "Valid access successful" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception on valid access: " << e.what() << std::endl;
    }
    
    try {
        arr[-1] = 100;
        std::cout << "This should not print!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception on negative index: " << e.what() << std::endl;
    }
    
    try {
        arr[3] = 100;
        std::cout << "This should not print!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception on too large index: " << e.what() << std::endl;
    }
    
    std::cout << std::endl << "===== Const Array Test =====" << std::endl;

    Array<int> temp(2);
    temp[0] = 111;
    temp[1] = 222;
    
    const Array<int> constArray(temp);
    
    std::cout << "constArray[0] = " << constArray[0] << std::endl;
    std::cout << "constArray[1] = " << constArray[1] << std::endl;
    
    // constArray[0] = 999;
    
    return 0;
}
