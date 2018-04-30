//
// Created by gordonzu on 4/28/18.
//

#ifndef AICPP_DYN_OBJECT_H
#define AICPP_DYN_OBJECT_H

#include <iostream>
#include <map>
#include <memory>

template<class Tkey, class Tval>
class DynObject
{
    std::string type;
    Tval value;
    std::multimap<Tkey, Tval> attrib;

protected:
    DynObject()=default;

public:
    virtual ~DynObject()=0;
    void set_attribute(Tkey key, Tval val);
    Tval get_attribute(Tkey key) const;
    void get_type();
    void describe_attributes();
    std::string& get_string();
    unsigned long get_map_size();
    bool has_suffix(std::string& str, const std::string& suffix);

    std::multimap<Tkey, Tval> create_attrib_map();
    std::multimap<Tkey, Tval> get_map() const;
};

#endif //AICPP_DYN_OBJECT_H
