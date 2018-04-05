//
// Created by gordonzu on 4/4/18.
//

#include <memory>
#include <unordered_map>
#include <iostream>
#include "table.h"

template<class T>
Table<T>::Table(std::vector<std::string> &rh,
                      std::vector<std::string> &ch) :
                      row_headers{rh},
                      col_headers{ch} {

    for (auto& rhs: row_headers) {
        rows.emplace(rhs, std::unordered_map<std::string, T>());
    }
}

template<class T>
void Table<T>::set_values(const std::string& rowh, const std::string& colh, T val) {
    auto it = rows.find(rowh);
    it->second.emplace(colh, val);
}

template<class T>
T* Table<T>::get_values(const std::string& rowh, const std::string& colh) {

    auto it = rows.find(rowh);
    if (it != rows.end()) {
        auto i = it->second.find(colh);
        if (i != it->second.end()) {
            val = i->second;
            return &val;
        }
    }
    return nullptr;
}
/*
template<class T>
bool Table<T>::get_values(const std::string& rowh, const std::string& colh) {

    auto it = rows.find(rowh);
    if (it != rows.end()) {
        auto i = it->second.find(colh);
        if (i != it->second.end()) {
            val = i->second;
            return true;
        }
    }
    return false;
}
*/
template<class T>
T Table<T>::get_val() {
    return val;
}

template<class T>
const char* Table<T>::talk() {
    return "Hello Table.";
}

template<class T>
size_t Table<T>::map_size() {
    return rows.size();
}






