//
// Created by gordonzu on 4/20/18.

#include "compares.h"

namespace util
{
    bool vec_compare(const std::vector<std::unique_ptr<Percept>>& a,
                     const std::vector<std::unique_ptr<Percept>>& b)
    {
        if (a.size() != b.size()) return false;

        for (unsigned i = 0; i < a.size(); ++i)
            if (!(*(a[i]) == *(b[i]))) return false;

        return true;
    }

    std::string& print_vec(const std::vector<std::unique_ptr<Percept>>& v, std::string& str)
    {
        for (unsigned i = 0; i <= v.size(); ++i) {
            str.append(v[i]->get_string());
            if (i + 1  == v.size()) break;
            str.append(", ");
        }
        return str;
    }
}


