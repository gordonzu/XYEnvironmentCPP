// xy_environment.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <memory>
#include "environment/xyenv/xy_environment.h"

XYEnvironment::XYEnvironment(unsigned w, unsigned h): matrix{w,h}
{
    assert (w > 0);
    assert (h > 0);
}

XYEnvironment::~XYEnvironment()
{
}

size_t XYEnvironment::get_matrix_size()
{
    return matrix.vector_size();
}


void XYEnvironment::add_to(Object* eo, XYLocation& loc)
{
    matrix.add_object(eo, loc);
    add_obj(eo);
}


XYLocation* XYEnvironment::get_location(Object* eo)
{
    return matrix.get_object_location(eo);

    /*
    Vector::iterator itPairs;
    std::vector<Object*>::iterator itEnvs;

    for (itPairs = vec_pairs.begin(); itPairs!= vec_pairs.end(); ++itPairs) {  
        for (itEnvs = itPairs->second.begin(); 
                      itEnvs != itPairs->second.end(); 
                      ++itEnvs) {
            if (*itEnvs == eo) {
                xyuniq = std::make_unique<XYLocation>(itPairs->first);
                return xyuniq.get();
            }
        }
    }
    return nullptr;
    */
}

/*
std::vector<Object*>& XYEnvironment::get_at(XYLocation& loc)
{
    Vector::iterator it;

    it = std::find_if(vec_pairs.begin(), 
                      vec_pairs.end(), 
                      [loc](std::pair<XYLocation, std::vector<Object*>>& mypair) {
                            return (mypair.first == loc);
    });

    if (it != vec_pairs.end()) {
        return it->second;
    } else {
        vec_objs = std::make_unique<std::vector<Object*>>();
        vec_pairs.push_back(std::make_pair(loc, *vec_objs));
        return *vec_objs;
    }
}

Vector& XYEnvironment::get_vector()
{
    return vec_pairs;
}

void XYEnvironment::move_object(Object* eo, const XYLocation::Direction& dir)
{
    XYLocation* temp = get_location(eo);

    if (temp != nullptr) {
        temp = temp->location_at(dir);
        if (!(is_blocked(*temp))) {
            add_to(eo, *temp);
        }
    }    
}

bool XYEnvironment::is_blocked(XYLocation& loc) 
{
    for (auto& eo : get_at(loc)) {
        if (Wall* w = dynamic_cast<Wall*>(eo)) {      
            return true;
        }
    }
    return false;
}
*/

