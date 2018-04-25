//
// Created by gordonzu on 4/4/18.
//

#include <memory>
#include <iostream>
#include "table.h"

template<class Trow, class Tcol, class Tval>
Table<Trow, Tcol, Tval>::Table(std::vector<Trow> &rh,
                      std::vector<Tcol> &ch) :
                      row_headers{rh},
                      col_headers{ch}
{
    for (auto& rhs: row_headers) {
        rows.emplace(rhs, std::map<Tcol, Tval>());
    }
}

template<class Trow, class Tcol, class Tval>
void Table<Trow, Tcol, Tval>::set_values(const Trow& rowh, const Tcol& colh, Tval val)
{
    auto it = rows.find(rowh);
    if (it == rows.end()) std::cout << "rowheader not found... " << std::endl;
    it->second.emplace(colh, val);
}

template<class Trow, class Tcol, class Tval>
bool Table<Trow, Tcol, Tval>::get_values(const Trow& rowh, const Tcol& colh, Tval& val)
{
    auto it = rows.find(rowh);
    if (it != rows.end()) {
        auto i = it->second.find(colh);
        if (i != it->second.end()) {
            val = i->second;
            return true;
        } else {
            //std::cout << "No colheader... " << std::endl;
        }
    } else {
        //std::cout << "No rowheader... " << std::endl;
    }
    return false;
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
template<class Trow, class Tcol, class Tval>
Tval Table<Trow, Tcol, Tval>::get_val() {
    return val;
}

template<class Trow, class Tcol, class Tval>
const char* Table<Trow, Tcol, Tval>::talk() {
    return "Hello Table.";
}

template<class Trow, class Tcol, class Tval>
size_t Table<Trow, Tcol, Tval>::map_size() {
    return rows.size();
}






