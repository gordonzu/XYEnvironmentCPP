// XYEnvironmentState.cpp

#include "Environment/xyenv/include/XYEnvironmentState.h"

XYEnvironmentState::XYEnvironmentState(int w, int h): width_{w}, height_{h}, vecPairs{std::vector<LocationPair>()} 
{
    initState();
}                           

void XYEnvironmentState::moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation* loc)
{
    // For every LocationPair in vecPairs, search the EO vector for the passed in EO.
    // If found, erase it.
    // Call getObjectsAt, pass it the XYLocation
    // add the passed in EO object to the EO vector returned from getObjectsAt 
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

std::vector<EnvironmentObject*>& XYEnvironmentState::getObjectsAt(XYLocation* loc)
{
    // For every LocationPair in vecPairs, search for the passed in XYLocation 
    // If found, return the corresponding vector of EO
    // If not found, add the XYLocation and a new empty EO vector to vecPairs and return the EO vector
    std::vector<LocationPair>::iterator it;

    it = std::find_if(vecPairs.begin(), vecPairs.end(), [loc](LocationPair& mypair) {
        return (*(mypair.get_xy()) == *loc);
    });

    if (it != vecPairs.end()) {
        return it->get_envs();
    } else {
        env_vector = std::vector<EnvironmentObject*>();
        vecPairs.push_back(LocationPair(loc, env_vector));
        return env_vector;
    }
}

 
XYLocation* XYEnvironmentState::getCurrentLocationFor(EnvironmentObject* eo) 
{
    std::vector<LocationPair>::iterator itPairs;
    std::vector<EnvironmentObject*>::iterator itEnvs;

    for (itPairs = vecPairs.begin(); itPairs!= vecPairs.end(); ++itPairs) {
        for (itEnvs = itPairs->get_envs().begin(); itEnvs != itPairs->get_envs().end(); ++itEnvs) {
            if (*itEnvs == eo) {
                XYLocation* xy = itPairs->get_xy();
                return xy;
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
            vecPairs.push_back(LocationPair(new XYLocation(x, y), std::vector<EnvironmentObject*>()));
        }
    }
}

EnvironmentObject* XYEnvironmentState::get_pointer()
{
    return env_ptr;        
}


