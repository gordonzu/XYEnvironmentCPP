//
// Created by gordonzu on 4/24/18.
//

#ifndef AICPP_RULE_H
#define AICPP_RULE_H

#include "agent/dynamic_attributes.h"

class Condition
{
public:
    virtual bool evaluate()=0;
};

#endif //AICPP_RULE_H
