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
    std::string& get_type();
    std::string& describe_attributes(std::string& type);
    std::string& get_string();
    unsigned long get_map_size();

    std::multimap<const char*, const char*> create_attrib_map();
    std::multimap<const char*, const char*> get_map() const;
    void erase_map();

protected:
    DynamicAttributes()=default;

private:
    std::string type;
    std::multimap<const char*, const char*> attrib;
};
#endif //AICPP_DYNAMIC_ATTRIBUTES_H


