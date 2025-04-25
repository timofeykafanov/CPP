#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
    int id;
    std::string name;
    double value;
    
    Data(int _id = 0, const std::string& _name = "", double _value = 0.0) :
        id(_id), name(_name), value(_value) {}
};

#endif
