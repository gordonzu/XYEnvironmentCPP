//
// Created by gordonzu on 4/29/18.
//

#ifndef AICPP_TYPES_H
#define AICPP_TYPES_H

#include <string>

class Boolean {
    bool flag;
    std::string str_rep;

public:
    Boolean(): flag{false}, str_rep{"false"}
    {
    }

    ~Boolean()
    {
    }

    Boolean(bool b)
    {
        flag = b;
        if (flag) {
            str_rep = "true";
        } else {
            str_rep = "false";
        }
    }

    Boolean(const Boolean& other)
    {
        flag = other.flag;
        str_rep = other.str_rep;
    }

    Boolean& operator=(Boolean& rhs)
    {
        if (&rhs != this) {
            flag = rhs.flag;
            str_rep = rhs.str_rep;
        }
        return *this;
    }

    Boolean& operator=(bool rhs)
    {
        flag = rhs;
        if (flag) {
            str_rep = "true";
        } else {
            str_rep = "false";
        }

        return *this;
    }

    bool operator==(Boolean& rhs)
    {
        return flag == rhs.flag && str_rep == rhs.str_rep;
    }

    bool operator!=(Boolean& rhs)
    {
        return flag != rhs.flag || str_rep != rhs.str_rep;
    }

    std::string print()
    {
        return str_rep;
    }
};

#endif //AICPP_TYPES_H













