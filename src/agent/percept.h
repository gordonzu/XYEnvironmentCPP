//
// Created by gordonzu on 4/16/18.
//

#ifndef AICPP_PERCEPT_H
#define AICPP_PERCEPT_H

#include "dynamic_attributes.h"

class Percept
{
public:
    virtual ~Percept() {}

protected:
    Percept()=default;
};

class DynamicPercept: public Percept, public DynamicAttributes
{
public:
    DynamicPercept()=default;
    ~DynamicPercept() override =default;

    DynamicPercept(const char* key, const char* val)
    {
        set_attribute(key, val);
    }

    DynamicPercept(const char* key1, const char* val1, const char* key2, const char* val2)
    {
        set_attribute(key1, val1);
        set_attribute(key2, val2);
    }

    bool operator==(const DynamicPercept& other) const
    {
        return (typeid(*this) == typeid(other)) && (get_map() == other.get_map());
    }
};

#endif //AICPP_PERCEPT_H
