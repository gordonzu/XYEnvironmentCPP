// xy_environment.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <memory>
#include "environment/xyenv/xy_environment.h"
//#include "util/datastructure/xy_location.h"
//#include "agent/agent.h"

using VectorOfPairs = std::vector<std::pair<XYLocation, std::vector<Object*>>>;

XYEnvironment::XYEnvironment()
{
}

XYEnvironment::XYEnvironment(int w, int h): width_{w}, height_{h}, vecPairs{VectorOfPairs()} 
{
    assert (w > 0);
    assert (h > 0);

    for (int x = 1; x <= width_; ++x) {
        for (int y = 1; y <= height_; ++y) {
           vecPairs.push_back(std::make_pair(XYLocation(x, y), std::vector<Object*>()));
        }
    }
}

XYEnvironment::~XYEnvironment()
{
}

void XYEnvironment::add_to(Object* eo, XYLocation& loc)
{
   for (auto& x : vecPairs) {
        for (auto it = x.second.begin(); it != x.second.end(); ) {
            if ((*it) == eo) {
                it = x.second.erase(it);
            } else {
                ++it;
            }
        }
    }
    get_at(loc).push_back(eo);
    add_eo(eo);
}

std::shared_ptr<XYLocation> XYEnvironment::get_location(Object* eo)
{
    VectorOfPairs::iterator itPairs;
    std::vector<Object*>::iterator itEnvs;

    for (itPairs = vecPairs.begin(); itPairs!= vecPairs.end(); ++itPairs) {
        for (itEnvs = itPairs->second.begin(); itEnvs != itPairs->second.end(); ++itEnvs) {
            if (*itEnvs == eo) {
                xy_ = itPairs->first;
                return std::make_shared<XYLocation>(xy_);
            }
        }
    }
    return nullptr;
}

std::vector<Object*>& XYEnvironment::get_at(XYLocation& loc)
{
    VectorOfPairs::iterator it;

    it = std::find_if(vecPairs.begin(), vecPairs.end(), [loc](std::pair<XYLocation, std::vector<Object*>>& mypair) {
        return (mypair.first == loc);
    });

    if (it != vecPairs.end()) {
        return it->second;
    } else {
        env_vector = std::make_unique<std::vector<Object*>>();
        vecPairs.push_back(std::make_pair(loc, *env_vector));
        return *env_vector;
    }
}

std::vector<std::pair<XYLocation, std::vector<Object*>>>& XYEnvironment::get_vector()
{
    return vecPairs;
}

void XYEnvironment::move_object(Object* eo, const XYLocation::Direction& dir)
{
    std::shared_ptr<XYLocation> temp = get_location(eo);

    if (temp != nullptr) {
        temp = temp.get()->location_at(dir);
        if (!(is_blocked(*(temp.get())))) {
            //move_to(eo, *(temp.get()));
            add_to(eo, *(temp.get()));
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


