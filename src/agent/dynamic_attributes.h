//
// Created by gordonzu on 4/16/18.
//

#ifndef AICPP_DYNAMIC_ATTRIBUTES_H
#define AICPP_DYNAMIC_ATTRIBUTES_H
#include <unordered_map>
#include <iostream>

template<class Tkey, class Tval>
class DynamicAttributes {
    std::unordered_map<Tkey, Tval> attributes;

protected:
    DynamicAttributes()=default;

public:
    void set_attribute(const Tkey& key, const Tval& val) {
        attributes.emplace(key, val);
        //std::cout << "Map size: " << attributes.size() << std::endl;
        //auto it = attributes.find("name");
        //std::cout << "Key: " << it->first << " Value: " << it->second << std::endl;
    }

    const Tval get_attribute(const Tkey& key) const {
        auto it = attributes.find(key);
        if (it != attributes.end()) {
            return it->second;
        }
        return nullptr;
    }

    std::unordered_map<Tkey, Tval> get_map() const {
        return attributes;
    };
};

#endif //AICPP_DYNAMIC_ATTRIBUTES_H


