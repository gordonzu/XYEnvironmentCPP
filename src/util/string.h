//
// Created by gordonzu on 4/29/18.
//

#ifndef AICPP_STRING_H
#define AICPP_STRING_H

#include <string>
#include <cstring>

class String
{
    std::string str_internal;
    char* ptr_internal;

public:
    String()
    {
    }

    String(std::string& str): str_internal{str}, ptr_internal{&str[0u]}
    {
    }

    String(const char* str): str_internal{str}
    {
        ptr_internal = (char*)malloc(sizeof(str));
        std::strcpy(ptr_internal, str);
    }

    String(const String& other)
    {
        str_internal = other.str_internal;
        ptr_internal = other.ptr_internal;
    }

    String(String& other)
    {
        str_internal = other.str_internal;
        ptr_internal = other.ptr_internal;
    }

    String(String&& other)
    {
        str_internal = other.str_internal;
        ptr_internal = other.ptr_internal;
    }

    String& operator=(String& rhs)
    {
        if (&rhs != this) {
            str_internal = rhs.str_internal;
            ptr_internal = rhs.ptr_internal;
        }
        return *this;
    }

    String& operator=(const char* rhs)
    {
        str_internal = rhs;
        ptr_internal = (char*)malloc(sizeof(rhs));
        std::strcpy(ptr_internal, rhs);
        return *this;
    }

    friend bool operator==(const String& lhs, const String& rhs)
    {
        return lhs.str_internal == rhs.str_internal &&
                (std::strcmp(lhs.ptr_internal, rhs.print_c()) == 0);
    }

    bool operator!=(String& rhs)
    {
        return str_internal != rhs.str_internal ||
                (std::strcmp(ptr_internal, rhs.print_c()) != 0);
    }

    friend bool operator<(const String& lhs, const String& rhs)
    {
        return lhs.str_internal < rhs.str_internal;
    }

    const char* print_c() const
    {
        return str_internal.c_str();
    }

    std::string print() const
    {
        return str_internal;
    }
};

#endif //AICPP_STRING_H
