//
// Created by gordonzu on 4/20/18.

#include "compares.h"

namespace util
{
    bool vec_compare(std::vector<std::unique_ptr<Percept>> a, std::vector<std::unique_ptr<Percept>> b)
    {
        if (a.size() != b.size())
            return false;

        for (unsigned i = 0; i < a.size(); ++i) {
            auto p1 = *a[i];
            auto p2 = *b[i];
            if (!(p1 == p2)) return false;
        }
        return true;
    }
}


