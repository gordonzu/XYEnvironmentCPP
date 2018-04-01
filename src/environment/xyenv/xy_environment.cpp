// xy_environment.cpp

#include <iostream>
#include <cassert>
#include <memory>
#include <algorithm>
#include <cmath>
#include "environment/xyenv/xy_environment.h"

XYEnvironment::XYEnvironment(unsigned w, unsigned h): width{w}, height{h}, matrix{w,h} {
    assert (width > 0);
    assert (height > 0);

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
    //std::cout << "Set size after returning from Matrix: " << get_set_size(loc) << std::endl;
    add_obj(eo);
}

XYLocation* XYEnvironment::get_location(Object* eo) {
    return matrix.get_object_location(eo);
}

void XYEnvironment::move_object(Object* eo, const XYLocation::Direction& dir) {
    matrix.move_object(eo, dir);
}

bool XYEnvironment::is_blocked(XYLocation &xy) {
    return matrix.is_blocked(xy);
}

bool XYEnvironment::is_blocked(XYLocation &&xy) {
    return matrix.is_blocked(xy);
}

std::set<Object*>& XYEnvironment::get_objects_near(Object* obj, unsigned rad) {
    near_set = std::make_unique<std::set<Object*>>();
    XYLocation* xy = get_location(obj);

    for (auto& v : get_vector()) {
        if (in_radius(rad, *xy, v.first)) {
            near_set->insert(v.second.begin(), v.second.end());
        }
    }

    auto search = near_set->find(obj);
    if (search != near_set->end())
        near_set->erase(search);

    return *near_set;
}

bool XYEnvironment::in_radius(unsigned rad, XYLocation& loca, XYLocation& locb) {
    int xdiff = loca.getx() - locb.getx();
    int ydiff = loca.gety() - locb.gety();

    return std::sqrt((xdiff * xdiff) + (ydiff * ydiff)) <= rad;
}

Vector& XYEnvironment::get_vector() {
    return matrix.get_vector();
}

void XYEnvironment::make_perimeter() {

    for (unsigned i = 0; i < width; ++i) {
        std::unique_ptr<XYLocation> xy1 = std::make_unique<XYLocation>(i, 0);
        std::unique_ptr<XYLocation> xy2 = std::make_unique<XYLocation>(i, height - 1);
        std::unique_ptr<Object> wall1 = std::make_unique<Wall>();
        std::unique_ptr<Object> wall2 = std::make_unique<Wall>();
        add_to(wall1.get(), *xy1);
        add_to(wall2.get(), *xy2);
    }

    for (unsigned i = 0; i < height; ++i) {
        std::unique_ptr<XYLocation> xy1 = std::make_unique<XYLocation>(0, i);
        std::unique_ptr<XYLocation> xy2 = std::make_unique<XYLocation>(width - 1, i);
        std::unique_ptr<Object> wall1 = std::make_unique<Wall>();
        std::unique_ptr<Object> wall2 = std::make_unique<Wall>();
        add_to(wall1.get(), *xy1);
        add_to(wall2.get(), *xy2);
    }

    /*std::unique_ptr<XYLocation> xy1 = std::make_unique<XYLocation>(0, 0);
    std::unique_ptr<Object> wall1 = std::make_unique<Wall>();
    add_to(wall1.get(), *xy1);*/
}

Vector::iterator XYEnvironment::has_xy(XYLocation& xy) {
    return matrix.has_xy(xy);
}
































