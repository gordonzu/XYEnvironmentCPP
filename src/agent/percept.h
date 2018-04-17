//
// Created by gordonzu on 4/16/18.
//

#ifndef AICPP_PERCEPT_H
#define AICPP_PERCEPT_H

#include "dynamic_attributes.h"

class Percept {
public:
    virtual ~Percept() {}

protected:
    Percept()=default;
};

class DynamicPercept: public Percept,
                      public DynamicAttributes<const char*, const char*> {
public:
    DynamicPercept()=default;
    ~DynamicPercept() override =default;

    DynamicPercept(const char* key, const char* val) {
        set_attribute(key, val);
    }
};

#endif //AICPP_PERCEPT_H
