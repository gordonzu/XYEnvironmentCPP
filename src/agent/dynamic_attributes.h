//
// Created by gordonzu on 4/16/18.
//

#ifndef AICPP_DYNAMIC_ATTRIBUTES_H
#define AICPP_DYNAMIC_ATTRIBUTES_H
#include <iostream>
#include <map>
#include <memory>

class DynamicAttributes
{
public:
    virtual ~DynamicAttributes()=0;
    void set_attribute(const char* key, const char* val);
    const char* get_attribute(const char* key) const;
    static std::multimap<const char*, const char*> create_attrib_map();
    static std::multimap<const char*, const char*> get_map();

protected:
    DynamicAttributes()=default;

private:
    static std::multimap<const char*, const char*> attrib;
};
#endif //AICPP_DYNAMIC_ATTRIBUTES_H


