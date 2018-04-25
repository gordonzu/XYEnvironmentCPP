// Created by gordonzu on 4/17/18.

#include <assert.h>
#include "dynamic_object.h"

DynamicObject::~DynamicObject()
{
}

void DynamicObject::set_attribute(const char* key, const char* val)
{
    DynamicObject::attrib.emplace(key, val);
}

const char* DynamicObject::get_attribute(const char* key) const
{
    auto it = DynamicObject::attrib.find(key);
    if (it != DynamicObject::attrib.end()) {
        return it->second;
    }
    return nullptr;
}

std::multimap<const char*, const char*> DynamicObject::get_map() const
{
    return attrib;
}

std::multimap<const char*, const char*> DynamicObject::create_attrib_map()
{
    std::multimap<const char*, const char*> map;
    return map;
}

std::string& DynamicObject::get_type()
{
    type = typeid(*this).name();

    if (type.size() <= size_t(10))
        return type = type.substr(1, type.size());

    return type = type.substr(2, type.size());
}

std::string& DynamicObject::describe_attributes(std::string& type)
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

std::string& DynamicObject::get_string()
{
    type.clear();
    type = get_type();
    return describe_attributes(type);
}

unsigned long DynamicObject::get_map_size()
{
    return attrib.size();
}


/*
void DynamicObject::erase_map()
{
    auto it = attrib.begin();
    while (it != attrib.end()) {
        it  = attrib.erase(it);
    }
}
*/


/*
template<class Tkey, class Tval>
DynamicObject::AttribMap DynamicAttributes::attrib = []
{
    AttribMap map;
    return map;
}();
*/

//std::multimap<const char*, const char*> DynamicObject::attrib = DynamicAttributes::create_attrib_map();


