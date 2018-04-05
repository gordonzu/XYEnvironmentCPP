//
// Created by gordonzu on 4/4/18.
//

#ifndef AICPP_TABLE_H
#define AICPP_TABLE_H

#include <string>
#include <unordered_map>
#include <vector>

template<class T>
class Table {
    std::vector<std::string> row_headers;
    std::vector<std::string> col_headers;
    std::unordered_map<std::string, std::unordered_map<std::string, T>> rows;
    T val;

public:
    Table () = default;
    Table(std::vector<std::string>& rh, std::vector<std::string>& ch);
    void set_values(const std::string& rowh, const std::string& colh, T val);
    T* get_values(const std::string& rowh, const std::string& colh);
    T get_val();
    const char* talk();
    size_t map_size();
};

#endif //AICPP_TABLE_H
