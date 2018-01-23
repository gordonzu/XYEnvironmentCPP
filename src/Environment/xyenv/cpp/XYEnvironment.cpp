// XYEnvironment.cpp

#include "Environment/xyenv/include/XYEnvironment.h"
#include "Environment/xyenv/include/Wall.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <memory>
#include "Util/datastructure/include/XYLocation.h"
#include "Agent/include/EnvironmentObject.h"

class XYEnvironmentState {
public:
    XYEnvironmentState(int w, int h);
    ~XYEnvironmentState();

    void                                moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation& loc);
    std::shared_ptr<XYLocation>         getCurrentLocationFor(EnvironmentObject* eo); 

    std::vector<std::pair<XYLocation, std::vector<EnvironmentObject*>>>& get_vector();


    std::vector<EnvironmentObject*>&    getObjectsAt(XYLocation& loc); 
    EnvironmentObject*                  get_pointer();

private:
    int                             width_;
    int                             height_;
    void                            initState(); 
    std::vector<EnvironmentObject*> env_vector;
    std::vector<std::pair<XYLocation, std::vector<EnvironmentObject*>>> vecPairs;
    EnvironmentObject*              env_ptr;
    XYLocation                      xy_;
    XYLocation                      NULL_XYLOCATION;

};

XYEnvironment::XYEnvironment()
{
}

XYEnvironment::XYEnvironment(int w, int h)//: envState(std::make_unique<XYEnvironmentState>(w, h))
{
    assert (w > 0);
    assert (h > 0);

    //envState = new XYEnvironmentState(w, h);
    envState = std::make_unique<XYEnvironmentState>(w, h);
}

XYEnvironment::~XYEnvironment()
{
    //delete envState;
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
                    vecPairs{std::vector<std::pair<XYLocation, std::vector<EnvironmentObject*>>>()}, 
                    NULL_XYLOCATION{XYLocation{0, 0}}
{
    initState();
}   

XYEnvironment::XYEnvironmentState::~XYEnvironmentState()
{
   //env_vector.clear(); 
   ///vecPairs.clear(); 
//    for (auto& x : vecPairs) {
//        delete x.get_xy();
//    }
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

 
std::shared_ptr<XYLocation> XYEnvironment::XYEnvironmentState::getCurrentLocationFor(EnvironmentObject* eo) 
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


std::vector<std::pair<XYLocation, std::vector<EnvironmentObject*>>>& XYEnvironment::XYEnvironmentState::get_vector()
{
    return vecPairs;
}

void XYEnvironment::XYEnvironmentState::initState()
{
    for (int x = 1; x <= width_; ++x) {
        for (int y = 1; y <= height_; ++y) {
           vecPairs.push_back(std::make_pair(XYLocation(x, y), std::vector<EnvironmentObject*>()));
        }
    }
}


