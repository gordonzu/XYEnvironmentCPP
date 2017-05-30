// XYEnvironmentState.h

#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>
#include <algorithm>
#include <cassert>

class XYLocation {
public:
    XYLocation() {}
    XYLocation(int w, int h): width_{w}, height_{h} {}
    void xylocation(); 
    bool operator==(const XYLocation& rhs) const; 

private:
    int width_;
    int height_;
};

class EnvironmentObject {
public:
    virtual ~EnvironmentObject();
};

class Agent: public EnvironmentObject {
public:
    virtual ~Agent();
};

class AbstractAgent: public Agent {
public:
    virtual ~AbstractAgent();
};

class MockAgent: public AbstractAgent {
public:
    virtual ~MockAgent(); 
};

class LocationPair {
public:
    LocationPair() {}
    LocationPair(XYLocation* xy, std::vector<EnvironmentObject*>* envs);

    XYLocation* xy_;
    std::vector<EnvironmentObject*>* envs_;    
};

class XYEnvironmentState {
public:
    XYEnvironmentState(int w, int h);
    void addObjectToLocation(EnvironmentObject* eo, XYLocation* loc); 
    void moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation* loc);
    std::vector<EnvironmentObject*>* getObjectsAt(XYLocation* loc); 
    void addEnvironmentObject(EnvironmentObject* eo); 
    XYLocation* getCurrentLocationFor(EnvironmentObject* eo); 
    std::vector<LocationPair>* getVector(); 

private:
    std::vector<LocationPair>*          vecPairs;
    std::vector<EnvironmentObject*>*    vecEnvs;
    int                                 width_;
    int                                 height_;
    void initState(); 
};


class AbstractEnvironment {
public:
    std::vector<Agent*> getAgents() {
        return agents;
    }

    void addEnvironmentObject(EnvironmentObject* eo) {
        envObjects.push_back(eo);
        if (Agent* a = dynamic_cast<Agent*>(eo)) {
            agents.push_back(a);            
        }          
    }

protected:
    std::vector<EnvironmentObject*> envObjects;
    std::vector<Agent*> agents;
};

class XYEnvironment: public AbstractEnvironment {
public:
    XYEnvironment() {}
    XYEnvironment(int w, int h) {
        assert (w > 0);
        assert (h > 0);

        envState = new XYEnvironmentState(w, h);        
    }

    virtual ~XYEnvironment() {}

    void addObjectToLocation(EnvironmentObject* eo, XYLocation* loc) {
        moveObjectToAbsoluteLocation(eo, loc);
    }

    void moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation* loc) {
        envState->moveObjectToAbsoluteLocation(eo, loc);
        addEnvironmentObject(eo);
    }

    XYLocation* getCurrentLocationFor(EnvironmentObject* eo) {
        return envState->getCurrentLocationFor(eo);
    }

private:
    XYEnvironmentState* envState;
};




































