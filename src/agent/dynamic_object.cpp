// Created by gordonzu on 4/17/18.

#include <assert.h>
#include "dynamic_object.h"

DynamicObject::~DynamicObject()
{
}

void DynamicObject::set_attribute(const char* key,  const char* val)
{
    //std::cout << "setting in attrib value: " << key << "  " << val << std::endl;
    DynamicObject::attrib.emplace(key, val);
    //std::cout << "size of attrib: " << attrib.size() << std::endl;
    //std::multimap<const char*, const char*>::const_iterator cit = attrib.begin();

    //std::cout << "-----------------------------------------------------" << std::endl;
    //std::cout << "-------------------------print the map----------------------------" << std::endl;
    /*while (cit != attrib.end()) {
        std::cout << "Key: " << cit->first << "  " << "Value: " << cit->second << std::endl;
        ++cit;
    }*/
    //std::cout << "-----------------------------------------------------" << std::endl;
}

const char* DynamicObject::get_attribute(const char* key) const
{

    //std::cout << "--------------------------------------------- " << std::endl;
    //std::cout << "Calling get_attributes()... " << std::endl;
    //std::cout << "--------------------------------------------- " << std::endl;
    //std::cout << "size of attrib: " << attrib.size() << std::endl;
    //std::cout << "The key being used to search: " << key << std::endl;

    //std::multimap<const char*, const char*>::const_iterator cit = attrib.begin();
    //std::cout << "-----------------------------------------------------" << std::endl;
    /*while (cit != attrib.end()) {
        std::cout << "Key: " << cit->first << "  " << "Value: " << cit->second << std::endl;
        ++cit;
    }
    std::cout << "-----------------------------------------------------" << std::endl;
*/
    auto it = DynamicObject::attrib.find(key);
    //std::cout << "Printing the value: " << it->second << std::endl;
    if (it != DynamicObject::attrib.end()) {
        return it->second;
    }
   // std::cout << "returning nullptr..." << std::endl;
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


