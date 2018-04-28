//
// Created by gordonzu on 4/24/18.
//

#ifndef AICPP_RULE_H
#define AICPP_RULE_H

#include <agent/action.h>
#include "agent/dynamic_object.h"
#include "condition.h"

using namespace ag;

class Rule
{
    Condition& condition;
    Action action;

public:
    Rule(Condition& c, const Action& a): condition{c}, action{a} {}

    bool evaluate(DynamicObject& o)
    {
         return condition.evaluate(o);
    }

    bool evaluate(DynamicObject&& o)
    {
        return evaluate(o);
    }

    const Action& get_action()
    {
        return action;
    }

    std::string string()
    {
        std::string out;
        out.append("if ");
        out.append(condition.string());
        out.append(" then ");
        out.append(action.string());
        out.append(".");
        return out;
    }
};
#endif //AICPP_RULE_H
