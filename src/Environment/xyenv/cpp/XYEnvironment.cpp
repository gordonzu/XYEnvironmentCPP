// XYEnvironment.cpp

#include "Environment/xyenv/include/XYEnvironment.h"
#include "Environment/xyenv/include/Wall.h"

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
    delete envState;
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
    //return envState->get_vector();
}

void XYEnvironment::moveObject(EnvironmentObject* eo, XYLocation::Direction& dir)
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


