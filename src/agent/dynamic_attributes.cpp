// Created by gordonzu on 4/17/18.

#include <assert.h>
#include "dynamic_attributes.h"

DynamicAttributes::~DynamicAttributes()
{
}

void DynamicAttributes::set_attribute(const char* key, const char* val)
{
    DynamicAttributes::attrib.emplace(key, val);
}

const char* DynamicAttributes::get_attribute(const char* key) const
{
    auto it = DynamicAttributes::attrib.find(key);
    if (it != DynamicAttributes::attrib.end()) {
        return it->second;
    }
    return nullptr;
}

std::multimap<const char*, const char*> DynamicAttributes::get_map() const
{
    return attrib;
}

std::multimap<const char*, const char*> DynamicAttributes::create_attrib_map()
{
    std::multimap<const char*, const char*> map;
    return map;
}

std::string& DynamicAttributes::get_type()
{
    type = typeid(*this).name();

    if (type.size() <= size_t(10))
        return type = type.substr(1, type.size());

    return type = type.substr(2, type.size());
}

std::string& DynamicAttributes::describe_attributes(std::string& type)
{
    type.append("[");
    bool first = true;
    for (auto x : attrib) {
        if (first) {
            first = false;
        } else {
            type.append(", ");
        }

        type.append(x.first);
        type.append("=");
        type.append(x.second);
    }
    type.append("]");
    return type;
}

std::string& DynamicAttributes::get_string()
{
    type.clear();
    type = get_type();
    return describe_attributes(type);
}

unsigned long DynamicAttributes::get_map_size()
{
    return attrib.size();
}
void DynamicAttributes::erase_map()
{
    auto it = attrib.begin();
    while (it != attrib.end()) {
        it  = attrib.erase(it);
    }
}



/*
template<class Tkey, class Tval>
DynamicAttributes::AttribMap DynamicAttributes::attrib = []
{
    AttribMap map;
    return map;
}();
*/

//std::multimap<const char*, const char*> DynamicAttributes::attrib = DynamicAttributes::create_attrib_map();


