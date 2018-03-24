//
// Created by gordonzu on 3/23/18.
//

#ifndef XYENVIRONMENT_MATRIX_H
#define XYENVIRONMENT_MATRIX_H

#include <memory>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "agent/object.h"
#include "xy_location.h"

using Vector = std::vector<std::pair<XYLocation, std::set<Object*>>>;

namespace xy {

    class Matrix {
    private:
        static Vector               vec;
        Vector::iterator            itv;
        std::set<Object*>::iterator its;

    public:
        Matrix(unsigned w, unsigned h);
        virtual ~Matrix();
        std::set<Object*>* get_set(XYLocation& loc);
        static Vector& get_vector();
        Vector::iterator has_xy(XYLocation& loc);
        bool add_object(Object* obj, XYLocation& xy);
        XYLocation* get_object_location(Object* obj);
        size_t set_size(XYLocation& xy);
        size_t vector_size();
    };
}

#endif //XYENVIRONMENT_MATRIX_H
