//
// Created by gordonzu on 4/16/18.
//

#ifndef AICPP_PERCEPT_H
#define AICPP_PERCEPT_H

#include "dynamic_object.h"

class Percept: public DynamicObject
{
public:
    Percept() {}
    ~Percept() override =default;

    Percept(const char* key, const char* val)
    {
        set_attribute(key, val);
    }

    Percept(const char* key1, const char* val1, const char* key2, const char* val2)
    {
        set_attribute(key1, val1);
        set_attribute(key2, val2);
    }

    bool operator==(const Percept& other) const
    {
        return (typeid(*this) == typeid(other)) && (get_map() == other.get_map());
    }

    bool operator<(const Percept& other) const
    {
        return get_map() > other.get_map() ? true : false;
    }
};

#endif //AICPP_PERCEPT_H














