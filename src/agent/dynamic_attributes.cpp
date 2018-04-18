// Created by gordonzu on 4/17/18.

#include "dynamic_attributes.h"

std::multimap<const char*, const char*> DynamicAttributes::attrib = DynamicAttributes::create_attrib_map();

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

std::multimap<const char*, const char*> DynamicAttributes::get_map()
{
    return DynamicAttributes::attrib;
}


std::multimap<const char*, const char*> DynamicAttributes::create_attrib_map()
{
    std::multimap<const char*, const char*> map;
    return map;
}


/*
template<class Tkey, class Tval>
DynamicAttributes::AttribMap DynamicAttributes::attrib = []
{
    AttribMap map;
    return map;
}();
*/



