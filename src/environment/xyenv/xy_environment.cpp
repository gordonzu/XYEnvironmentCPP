// xy_environment.cpp

#include <iostream>
#include <cassert>
#include <memory>
#include "environment/xyenv/xy_environment.h"

XYEnvironment::XYEnvironment(unsigned w, unsigned h): matrix{w,h} {
    assert (w > 0);
    assert (h > 0);
}

XYEnvironment::~XYEnvironment() {
}

size_t XYEnvironment::get_vector_size() {
    return matrix.vector_size();
}

size_t XYEnvironment::get_set_size(XYLocation& xy) {
    return matrix.set_size(xy);
}

void XYEnvironment::add_to(Object* eo, XYLocation& loc) {
    matrix.add_object(eo, loc);
    add_obj(eo);
}

XYLocation* XYEnvironment::get_location(Object* eo) {
    return matrix.get_object_location(eo);
}

void XYEnvironment::move_object(Object* eo, const XYLocation::Direction& dir) {
    matrix.move_object(eo, dir);
}


