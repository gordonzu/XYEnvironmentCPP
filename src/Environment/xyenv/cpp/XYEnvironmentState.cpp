// XYEnvironmentState.cpp

#include <new>
#include <iostream>
#include "Environment/xyenv/include/XYEnvironmentState.h"

XYEnvironmentState::XYEnvironmentState(int w, int h)
                   : width_{w}, height_{h}, vecPairs{std::vector<LocationPair>()}, NULL_XYLOCATION{XYLocation{0, 0}}
{
    initState();
}   

XYEnvironmentState::~XYEnvironmentState()
{
   //env_vector.clear(); 
   ///vecPairs.clear(); 
//    for (auto& x : vecPairs) {
//        delete x.get_xy();
//    }
}                        

void XYEnvironmentState::moveObjectToAbsoluteLocation(EnvironmentObject* eo, const XYLocation& loc)
{
   for (auto& x : vecPairs) {
        for (auto it = x.get_envs().begin(); it != x.get_envs().end(); ) {
            if ((*it) == eo) {
                it = x.get_envs().erase(it);
            } else {
                ++it;
            }
        }
    }
    getObjectsAt(loc).push_back(eo);
}

std::vector<EnvironmentObject*>& XYEnvironmentState::getObjectsAt(const XYLocation& loc)
{
    std::vector<LocationPair>::iterator it;

    it = std::find_if(vecPairs.begin(), vecPairs.end(), [loc](LocationPair& mypair) {
        return (mypair.get_xy() == loc);
    });

    if (it != vecPairs.end()) {
        return it->get_envs();
    } else {
        env_vector = std::vector<EnvironmentObject*>();
        vecPairs.push_back(LocationPair(loc, env_vector));
        return env_vector;
    }
}

 
std::shared_ptr<XYLocation> XYEnvironmentState::getCurrentLocationFor(EnvironmentObject* eo) 
{
    std::vector<LocationPair>::iterator itPairs;
    std::vector<EnvironmentObject*>::iterator itEnvs;

    for (itPairs = vecPairs.begin(); itPairs!= vecPairs.end(); ++itPairs) {
        for (itEnvs = itPairs->get_envs().begin(); itEnvs != itPairs->get_envs().end(); ++itEnvs) {
            if (*itEnvs == eo) {
                xy_ = itPairs->get_xy();
                //xy_.print();
                return std::make_shared<XYLocation>(xy_);
            }
        }
    }
    return nullptr;
}


std::vector<LocationPair>& XYEnvironmentState::get_vector()
{
    return vecPairs;
}

void XYEnvironmentState::initState()
{
    for (int x = 1; x <= width_; ++x) {
        for (int y = 1; y <= height_; ++y) {
           vecPairs.push_back(LocationPair(XYLocation(x, y), std::vector<EnvironmentObject*>()));
        }
    }
}


