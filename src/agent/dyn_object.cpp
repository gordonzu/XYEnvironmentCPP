//
// Created by gordonzu on 4/28/18.

#include <cstring>
#include "dyn_object.h"

template<class Tkey, class Tval>
DynObject<Tkey, Tval>::~DynObject()
{
}

template<class Tkey, class Tval>
void DynObject<Tkey, Tval>::set_attribute(Tkey key,  Tval val)
{
    DynObject::attrib.emplace(key, val);
}

template<class Tkey, class Tval>
Tval DynObject<Tkey, Tval>::get_attribute(Tkey key) const
{
    auto it = DynObject::attrib.find(key);
    if (it != DynObject::attrib.end()) {
        return it->second;
    }
    return nullptr;
}

template<class Tkey, class Tval>
std::multimap<Tkey, Tval> DynObject<Tkey, Tval>::get_map() const
{
    return attrib;
}

template<class Tkey, class Tval>
std::multimap<Tkey, Tval> DynObject<Tkey, Tval>::create_attrib_map()
{
    std::multimap<Tkey, Tval> map;
    return map;
}

template<class Tkey, class Tval>
std::string& DynObject<Tkey, Tval>::get_string()
{
    type.clear();
    get_type();
    describe_attributes();
    return type;
}

template<class Tkey, class Tval>
void DynObject<Tkey, Tval>::get_type()
{
    type = typeid(*this).name();

    if (has_suffix(type, "BooleanE")) {
        type = type.substr(2, (type.size()-19));
    } else {
        type = type.substr(2, (type.size()-14));
    }
}

template<class Tkey, class Tval>
void DynObject<Tkey, Tval>::describe_attributes()
{
    type.append("[");
    bool first = true;
    for (auto x : attrib) {

        if (first) {
            first = false;
        } else {
            type.append(", ");
        }

        type.append(x.first.print());
        type.append("=");
        type.append(x.second.print());
    }

    type.append("]");
}

template<class Tkey, class Tval>
bool DynObject<Tkey, Tval>::has_suffix(std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

template<class Tkey, class Tval>
unsigned long DynObject<Tkey, Tval>::get_map_size()
{
    return attrib.size();
}














/*
template<class Tkey, class Tval>
std::string& DynObject<Tkey, Tval>::describe_attributes(std::string& type)
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
*/


//(std::strcmp(typeid(val).name(), "PKc") == 0)













