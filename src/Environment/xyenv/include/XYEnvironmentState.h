// XYEnvironmentState.h

#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>
#include <algorithm>

class XYLocation {
public:
    XYLocation() {}
    XYLocation(int w, int h): width_{w}, height_{h} {}

    void xylocation() {
        std::cout << "XYLocation: width= " << width_ << " height= " << height_ << std::endl;
    }

    bool operator==(const XYLocation& rhs) const {
        return ((width_ == rhs.width_) && (height_ == rhs.height_));
    }

private:
    int width_;
    int height_;
};

class EnvironmentObject {
public:
    virtual ~EnvironmentObject() {}
};

class Agent: public EnvironmentObject {


};

class AbstractAgent: public Agent {


};

class MockAgent: public AbstractAgent {



};


class LocationPair {
public:
    LocationPair() {}
    LocationPair(XYLocation* xy, std::vector<EnvironmentObject*>* envs)
                : xy_{xy}, envs_{envs} {}

    XYLocation* xy_;
    std::vector<EnvironmentObject*>* envs_;    
};

class XYEnvironmentState {
public:
    XYEnvironmentState(int w, int h): width_{w}, height_{h} {
        initState();
    }

    void addObjectToLocation(EnvironmentObject* eo, XYLocation* loc) {
        moveObjectToAbsoluteLocation(eo, loc);
    }

    void moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation* loc) {
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

    std::vector<EnvironmentObject*>* getObjectsAt(XYLocation* loc) {
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

    void addEnvironmentObject(EnvironmentObject* eo) {
        vecEnvs->push_back(eo);
    }

    XYLocation* getCurrentLocationFor(EnvironmentObject* eo) {
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

    std::vector<LocationPair>* getVector() {
        return vecPairs;
    }

private:
    std::vector<LocationPair>*          vecPairs;
    std::vector<EnvironmentObject*>*    vecEnvs;
    int                                 width_;
    int                                 height_;

    void initState() {
        vecPairs = new std::vector<LocationPair>();
        vecEnvs  = new std::vector<EnvironmentObject*>();   

        for (int x = 1; x <= width_; ++x) {
            for (int y = 1; y <= height_; ++y) {
                vecPairs->push_back(LocationPair(new XYLocation(x, y), 
                                         new std::vector<EnvironmentObject*>()));
            }
        }
    }
};






































