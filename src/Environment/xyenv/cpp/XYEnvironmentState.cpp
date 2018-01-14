// XYEnvironmentState.cpp

#include "Environment/xyenv/include/XYEnvironmentState.h"

XYEnvironmentState::XYEnvironmentState(int w, int h): width_{w}, height_{h}, vecPairs{std::vector<LocationPair>()} 
{
    initState();
}                           

void XYEnvironmentState::moveObjectToAbsoluteLocation(PtrEnv eo, std::shared_ptr<XYLocation> loc)
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
    //getObjectsAt(loc).push_back(eo);
}

std::vector<PtrEnv>& XYEnvironmentState::getObjectsAt(std::shared_ptr<XYLocation> loc)
{
    std::vector<LocationPair>::iterator it;

    it = std::find_if(vecPairs.begin(), vecPairs.end(), [loc](LocationPair& mypair) {
        return (*(mypair.get_xy()) == *loc);
    });

    if (it != vecPairs.end()) {
        return it->get_envs();
    } else {
        env_vector = std::vector<PtrEnv>();
        vecPairs.push_back(LocationPair(loc, env_vector));
        return env_vector;
    }
}

 
std::shared_ptr<XYLocation> XYEnvironmentState::getCurrentLocationFor(PtrEnv eo) 
{
    std::vector<LocationPair>::iterator itPairs;
    std::vector<PtrEnv>::iterator itEnvs;

    for (itPairs = vecPairs.begin(); itPairs!= vecPairs.end(); ++itPairs) {
        for (itEnvs = itPairs->get_envs().begin(); itEnvs != itPairs->get_envs().end(); ++itEnvs) {
            if (*itEnvs == eo) {
                std::shared_ptr<XYLocation> xy = itPairs->get_xy();
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
            vecPairs.push_back(LocationPair(std::make_shared<XYLocation>(x, y), std::vector<PtrEnv>()));
        }
    }
}


