//
// Created by gordonzu on 4/29/18.
//

#ifndef AICPP_DYN_PERCEPT_H
#define AICPP_DYN_PERCEPT_H

#include "dyn_object.h"
#include "dyn_object.cpp"

template<class Tkey, class Tval>
class DynPercept: public DynObject<Tkey, Tval>
{
public:
    DynPercept() {}
    ~DynPercept() override =default;

    DynPercept(Tkey& key, Tval& val)
    {
        DynObject<Tkey, Tval>::set_attribute(key, val);
    }

    DynPercept(Tkey&& key, Tval&& val)
    {
        DynObject<Tkey, Tval>::set_attribute(key, val);
    }

    DynPercept(Tkey& key1, Tval& val1, Tkey& key2, Tval& val2)
    {
        DynObject<Tkey, Tval>::set_attribute(key1, val1);
        DynObject<Tkey, Tval>::set_attribute(key2, val2);
    }

    DynPercept(Tkey&& key1, Tval&& val1, Tkey&& key2, Tval&& val2)
    {
        DynObject<Tkey, Tval>::set_attribute(key1, val1);
        DynObject<Tkey, Tval>::set_attribute(key2, val2);
    }

    /*DynPercept(const DynPercept& other)
    {
    }*/

    DynPercept(const DynPercept& other1, const DynPercept& other2)
    {
    }

    bool operator==(const DynPercept& other) const
    {
        return (typeid(*this) == typeid(other)) && (this->DynObject<Tkey, Tval>::get_map() ==
                                                    other.DynObject<Tkey, Tval>::get_map());
    }

    bool operator<(const DynPercept& other) const
    {
        return this->DynObject<Tkey, Tval>::get_map() >
                     other.DynObject<Tkey, Tval>::get_map() ? true : false;
    }
};




















#endif //AICPP_DYN_PERCEPT_H
