//
// Created by gordonzu on 4/4/18.
//

#ifndef AICPP_TABLE_H
#define AICPP_TABLE_H

#include <string>
#include <unordered_map>
#include <vector>
#include <map>

template<class Trow, class Tcol, class Tval>
class Table {
    std::vector<Trow> row_headers;
    std::vector<Tcol> col_headers;
    std::map<Trow, std::map<Tcol, Tval>> rows;
    Tval val;

public:
    Table()=default;
    Table(std::vector<Trow>& rh, std::vector<Tcol>& ch);
    void set_values(const Trow& rowh, const Tcol& colh, Tval val);
    bool get_values(const Trow& rowh, const Tcol& colh, Tval& val);
    Tval get_val();
    const char* talk();
    size_t map_size();
};

#endif //AICPP_TABLE_H
