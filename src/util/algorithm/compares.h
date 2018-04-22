//
// Created by gordonzu on 4/20/18.
//

#ifndef AICPP_COMPARES_H
#define AICPP_COMPARES_H

#include <vector>
#include <algorithm>
#include <memory>
#include <agent/percept.h>

namespace util
{
    bool vec_compare(std::vector<std::unique_ptr<DynamicPercept>>, std::vector<std::unique_ptr<DynamicPercept>>);
    std::string& print_vec(std::vector<std::unique_ptr<DynamicPercept>>, std::string&);
}







#endif //AICPP_COMPARES_H
