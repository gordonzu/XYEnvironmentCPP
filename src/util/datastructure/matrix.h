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
#include "agent/base_object.h"
#include "xy_location.h"

using Vector = std::vector<std::pair<XYLocation, std::set<Object*>>>;

namespace xy {

    class Matrix {
    private:
        Vector                              vec;
        Vector::iterator                    itv;
        std::unique_ptr<std::set<Object*>>  set;
        std::set<Object*>::iterator         its;

    public:
        Matrix(unsigned w, unsigned h);
        virtual ~Matrix();
        std::set<Object*>*  get_set(const XYLocation& loc);
        Vector&             get_vector();
        Vector::iterator    has_xy(const XYLocation& loc);
        void                check_for_object(Object* obj);
        void                add_object(Object* obj, const XYLocation& xy);
        XYLocation*         get_object_location(Object* obj);
        void                move_object(Object* obj, const XYLocation::Direction& dir);
        bool                is_blocked(const XYLocation& xy);
        size_t              set_size(const XYLocation& xy);
        size_t              vector_size();
    };
}

#endif //XYENVIRONMENT_MATRIX_H
