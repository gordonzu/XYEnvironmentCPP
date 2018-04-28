//
// Created by gordonzu on 4/28/18.
//

#ifndef AICPP_CONDITION_H
#define AICPP_CONDITION_H

#include <agent/dynamic_object.h>
#include <cstring>

class Condition
{
public:
    virtual bool evaluate(DynamicObject& o)=0;
    virtual std::string string()=0;
};

class EqualCondition: public Condition
{
    const char* key;
    bool value;
    std::string boolstr;

public:
    EqualCondition(const char* str, bool b): key{str}, value{b}
    {
        value ? boolstr = "true" : boolstr = "false";
    }

    const char* eval(DynamicObject& o)
    {
        return o.get_attribute(key);
    }

    bool evaluate(DynamicObject& o) override {
        bool f;
        auto x = eval(o);

        if (x == nullptr)
            return false;

        if ((std::strcmp(x, "true") == 0)) {
            f = true;
        } else {
            f = false;
        }

        return f;
    }

    std::string string() override
    {
        std::string out;
        out.append(key);
        out.append("==");
        out.append(boolstr);
        return out;
    }
};

class NotCondition: public Condition
{
    Condition& con;
public:
    NotCondition(Condition& c): con{c} {}

    bool evaluate(DynamicObject& o) override {
        return !con.evaluate(o);
    }

    std::string string() override
    {
        std::string out;
        out.append("![");
        out.append(con.string());
        out.append("]");
        return out;
    }
};

class AndCondition: public Condition
{
    Condition& left;
    Condition& right;

public:
    AndCondition(Condition& l, Condition& r): left{l}, right{r} {}

    std::string string() override
    {
        std::string out;
        out.append("[");
        out.append(left.string());
        out.append(" && ");
        out.append(right.string());
        out.append("]");
        return out;
    }

    bool evaluate(DynamicObject& o)
    {
        return (left.evaluate(o) && right.evaluate(o));
    }
};

class OrCondition: public Condition
{
    Condition& left;
    Condition& right;

public:
    OrCondition(Condition& l, Condition& r): left{l}, right{r} {}

    std::string string() override
    {
        std::string out;
        out.append("[");
        out.append(left.string());
        out.append(" || ");
        out.append(right.string());
        out.append("]");
        return out;
    }

    bool evaluate(DynamicObject& o)
    {
        return (left.evaluate(o) || right.evaluate(o));
    }
};




































#endif //AICPP_CONDITION_H
