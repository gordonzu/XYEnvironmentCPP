// XYEnvironmentState.cpp

#include "Environment/xyenv/include/XYEnvironmentState.h"

XYEnvironmentState::XYEnvironmentState(int w, int h): width_{w}, height_{h} 
{
    initState();
}                           

void XYEnvironmentState::moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation* loc)
{
    for (auto& x : *vecPairs) {
        for (auto it = x.get_envs()->begin(); it != x.get_envs()->end(); ) {
            if ((*it) == eo) {
                delete *it;
                it = x.get_envs()->erase(it);
            } else {
                ++it;
            }
        }
    }
    getObjectsAt(loc)->push_back(eo);
}

std::vector<EnvironmentObject*>* XYEnvironmentState::getObjectsAt(XYLocation* loc)
{
    std::vector<LocationPair>::iterator it;
    std::vector<EnvironmentObject*>* env_vector;

    it = std::find_if(vecPairs->begin(), vecPairs->end(), [loc](LocationPair& mypair) {
        return (*(mypair.get_xy()) == *loc);
    });

    if (it != vecPairs->end()) {
        return it->get_envs();
    } else {
        env_vector = new std::vector<EnvironmentObject*>();
        vecPairs->push_back(LocationPair(loc, env_vector));
        return env_vector;
    }
}
 
XYLocation* XYEnvironmentState::getCurrentLocationFor(EnvironmentObject* eo) 
{
    std::vector<LocationPair>::iterator itPairs;
    std::vector<EnvironmentObject*>::iterator itEnvs;

    for (itPairs = vecPairs->begin(); itPairs!= vecPairs->end(); ++itPairs) {
        for (itEnvs = itPairs->get_envs()->begin(); itEnvs != itPairs->get_envs()->end(); ++itPairs) {
            if (*itEnvs == eo) {
                return itPairs->get_xy();
            }
        }
    }
    return nullptr;
}

std::vector<LocationPair>* XYEnvironmentState::get_vector()
{
    return vecPairs;
}

void XYEnvironmentState::initState()
{
    vecPairs = new std::vector<LocationPair>();

    for (int x = 1; x <= width_; ++x) {
        for (int y = 1; y <= height_; ++y) {
            vecPairs->push_back(LocationPair(new XYLocation(x, y), new std::vector<EnvironmentObject*>()));
        }
    }
}



















































































