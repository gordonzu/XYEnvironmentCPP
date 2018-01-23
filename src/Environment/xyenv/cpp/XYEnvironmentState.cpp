// XYEnvironmentState.cpp

#include <new>
#include <iostream>
#include "Environment/xyenv/include/XYEnvironmentState.h"

XYEnvironmentState::XYEnvironmentState(int w, int h)
                   : width_{w}, height_{h}, 
                    vecPairs{std::vector<std::pair<XYLocation, std::vector<EnvironmentObject*>>>()}, 
                    NULL_XYLOCATION{XYLocation{0, 0}}
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

void XYEnvironmentState::moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation& loc)
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
    getObjectsAt(loc).push_back(eo);
}

std::vector<EnvironmentObject*>& XYEnvironmentState::getObjectsAt(XYLocation& loc)
{
    //std::vector<std::pair<XYLocation, std::vector<EnvironmentObject*>>>::iterator it;
    std::vector<std::pair<XYLocation, std::vector<EnvironmentObject*>>>::iterator it;

    it = std::find_if(vecPairs.begin(), vecPairs.end(), [loc](std::pair<XYLocation, std::vector<EnvironmentObject*>>& mypair) {
        return (mypair.first == loc);
    });

    if (it != vecPairs.end()) {
        return it->second;
    } else {
        env_vector = std::vector<EnvironmentObject*>();
        vecPairs.push_back(std::make_pair(loc, env_vector));
        return env_vector;
    }
}

 
std::shared_ptr<XYLocation> XYEnvironmentState::getCurrentLocationFor(EnvironmentObject* eo) 
{
    std::vector<std::pair<XYLocation, std::vector<EnvironmentObject*>>>::iterator itPairs;
    std::vector<EnvironmentObject*>::iterator itEnvs;

    for (itPairs = vecPairs.begin(); itPairs!= vecPairs.end(); ++itPairs) {
        for (itEnvs = itPairs->second.begin(); itEnvs != itPairs->second.end(); ++itEnvs) {
            if (*itEnvs == eo) {
                xy_ = itPairs->first;
                //xy_.print();
                return std::make_shared<XYLocation>(xy_);
            }
        }
    }
    return nullptr;
}


std::vector<std::pair<XYLocation, std::vector<EnvironmentObject*>>>& XYEnvironmentState::get_vector()
{
    return vecPairs;
}

void XYEnvironmentState::initState()
{
    for (int x = 1; x <= width_; ++x) {
        for (int y = 1; y <= height_; ++y) {
           vecPairs.push_back(std::make_pair(XYLocation(x, y), std::vector<EnvironmentObject*>()));
        }
    }
}


