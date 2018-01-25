// xy_environment.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <memory>
#include "environment/xyenv/xy_environment.h"
#include "util/datastructure/xy_location.h"
#include "agent/agent.h"

using VectorOfPairs = std::vector<std::pair<XYLocation, std::vector<EnvironmentObject*>>>;

class XYEnvironment::XYEnvironmentState {
public:
    XYEnvironmentState(int w, int h);
    ~XYEnvironmentState();

    void                                moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation& loc);
    std::shared_ptr<XYLocation>         getCurrentLocationFor(EnvironmentObject* eo); 
    VectorOfPairs&                      get_vector();
    std::vector<EnvironmentObject*>&    getObjectsAt(XYLocation& loc); 
    EnvironmentObject*                  get_pointer();

private:
    int                                                 width_;
    int                                                 height_;
    VectorOfPairs                                       vecPairs;
    std::unique_ptr<std::vector<EnvironmentObject*>>    env_vector;
    EnvironmentObject*                                  env_ptr;
    XYLocation                                          xy_;
};

XYEnvironment::XYEnvironment()
{
}

XYEnvironment::XYEnvironment(int w, int h)
{
    assert (w > 0);
    assert (h > 0);

    envState = std::make_unique<XYEnvironmentState>(w, h);
}

XYEnvironment::~XYEnvironment()
{
}

void XYEnvironment::addObjectToLocation(EnvironmentObject* eo, XYLocation& loc)
{
    moveObjectToAbsoluteLocation(eo, loc);
}


void XYEnvironment::moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation& loc)
{
    envState->moveObjectToAbsoluteLocation(eo, loc);
    addEnvironmentObject(eo);
}

std::shared_ptr<XYLocation> XYEnvironment::getCurrentLocationFor(EnvironmentObject* eo)
{
    return envState->getCurrentLocationFor(eo);
}

std::vector<EnvironmentObject*>& XYEnvironment::getObjectsAt(XYLocation& loc)
{
    return envState->getObjectsAt(loc);
}

std::vector<std::pair<XYLocation, std::vector<EnvironmentObject*>>>& XYEnvironment::get_vector()
{
    return envState->get_vector();
}

void XYEnvironment::moveObject(EnvironmentObject* eo, const XYLocation::Direction& dir)
{
    std::shared_ptr<XYLocation> temp = envState->getCurrentLocationFor(eo);

    if (temp != nullptr) {
        temp = temp.get()->locationAt(dir);
        if (!(isBlocked(*(temp.get())))) {
            moveObjectToAbsoluteLocation(eo, *(temp.get()));
        }
    }    
}

bool XYEnvironment::isBlocked(XYLocation& loc) 
{
    for (auto& eo : envState->getObjectsAt(loc)) {
        if (Wall* w = dynamic_cast<Wall*>(eo)) {      
            return true;
        }
    }
    return false;
}

XYEnvironment::XYEnvironmentState::XYEnvironmentState(int w, int h)
                                                    : width_{w}, height_{h}, 
                                                    vecPairs{VectorOfPairs()} 
{
    for (int x = 1; x <= width_; ++x) {
        for (int y = 1; y <= height_; ++y) {
           vecPairs.push_back(std::make_pair(XYLocation(x, y), std::vector<EnvironmentObject*>()));
        }
    }
}   

XYEnvironment::XYEnvironmentState::~XYEnvironmentState()
{
}                        

void XYEnvironment::XYEnvironmentState::moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation& loc)
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

std::vector<EnvironmentObject*>& XYEnvironment::XYEnvironmentState::getObjectsAt(XYLocation& loc)
{
    VectorOfPairs::iterator it;

    it = std::find_if(vecPairs.begin(), vecPairs.end(), [loc](std::pair<XYLocation, std::vector<EnvironmentObject*>>& mypair) {
        return (mypair.first == loc);
    });

    if (it != vecPairs.end()) {
        return it->second;
    } else {
        env_vector = std::make_unique<std::vector<EnvironmentObject*>>();
        vecPairs.push_back(std::make_pair(loc, *env_vector));
        return *env_vector;
    }
}

 
std::shared_ptr<XYLocation> XYEnvironment::XYEnvironmentState::getCurrentLocationFor(EnvironmentObject* eo) 
{
    VectorOfPairs::iterator itPairs;
    std::vector<EnvironmentObject*>::iterator itEnvs;

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


VectorOfPairs& XYEnvironment::XYEnvironmentState::get_vector()
{
    return vecPairs;
}


