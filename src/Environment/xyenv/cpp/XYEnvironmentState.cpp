// XYEnvironmentState.cpp
#include "xyenv/include/XYEnvironmentState.h"

// XYLocation
void XYLocation::xylocation() 
{
    std::cout << "XYLocation: width= " << width_ << " height= " << height_ << std::endl;
}

bool XYLocation::operator==(const XYLocation& rhs) const 
{
        return ((width_ == rhs.width_) && (height_ == rhs.height_));
}

// EnvironmentObject
EnvironmentObject::~EnvironmentObject() 
{
}

// Agent
Agent::~Agent()
{
}

// AbstractAgent
AbstractAgent::~AbstractAgent()
{
}

// MockAgent
MockAgent::~MockAgent()
{
}

// LocationPair
LocationPair::LocationPair(XYLocation* xy, std::vector<EnvironmentObject*>* envs):
                           xy_{xy}, envs_{envs} 
{
} 

// XYEnvironmentstate 
XYEnvironmentState::XYEnvironmentState(int w, int h): width_{w}, height_{h} 
{
    initState();
}                           

void XYEnvironmentState::addObjectToLocation(EnvironmentObject* eo, XYLocation* loc)
{
    moveObjectToAbsoluteLocation(eo, loc);
}

void XYEnvironmentState::moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation* loc)
{
    for (auto& x : *vecPairs) {
        for (auto it = x.envs_->begin(); it != x.envs_->end(); ) {
            if ((*it) == eo) {
                delete *it;
                it = x.envs_->erase(it);
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
        return mypair.xy_ == loc;
    });

    if ((env_vector = it->envs_) == nullptr) {
        env_vector = new std::vector<EnvironmentObject*>();
        vecPairs->push_back(LocationPair(loc, env_vector));
    }
    return env_vector; 
}

void XYEnvironmentState::addEnvironmentObject(EnvironmentObject* eo)
{
    vecEnvs->push_back(eo);
}

XYLocation* XYEnvironmentState::getCurrentLocationFor(EnvironmentObject* eo) 
{
    std::vector<LocationPair>::iterator itPairs;
    std::vector<EnvironmentObject*>::iterator itEnvs;

    for (itPairs = vecPairs->begin(); itPairs!= vecPairs->end(); ++itPairs) {
        for (itEnvs = itPairs->envs_->begin(); itEnvs != itPairs->envs_->end(); ++itPairs) {
            if (*itEnvs == eo) {
                return itPairs->xy_;
            }
        }
    }
    return nullptr;
}

std::vector<LocationPair>* XYEnvironmentState::getVector()
{
    return vecPairs;
}

void XYEnvironmentState::initState()
{
    vecPairs = new std::vector<LocationPair>();
    vecEnvs  = new std::vector<EnvironmentObject*>();   

    for (int x = 1; x <= width_; ++x) {
        for (int y = 1; y <= height_; ++y) {
            vecPairs->push_back(LocationPair(new XYLocation(x, y), 
                                     new std::vector<EnvironmentObject*>()));
        }
    }
}

std::vector<Agent*> AbstractEnvironment::getAgents()
{
    return agents;
}

void AbstractEnvironment::addEnvironmentObject(EnvironmentObject* eo)
{
    envObjects.push_back(eo);
    if (Agent* a = dynamic_cast<Agent*>(eo)) {
        agents.push_back(a);            
    }          
}

XYEnvironment::XYEnvironment()
{
}

XYEnvironment::XYEnvironment(int w, int h)
{
    assert (w > 0);
    assert (h > 0);

    envState = new XYEnvironmentState(w, h);
}

XYEnvironment::~XYEnvironment()
{
}

void XYEnvironment::addObjectToLocation(EnvironmentObject* eo, XYLocation* loc)
{
    moveObjectToAbsoluteLocation(eo, loc);
}

void XYEnvironment::moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation* loc)
{
    envState->moveObjectToAbsoluteLocation(eo, loc);
    addEnvironmentObject(eo);
}

XYLocation* XYEnvironment::getCurrentLocationFor(EnvironmentObject* eo)
{
    return envState->getCurrentLocationFor(eo);
}


















































































