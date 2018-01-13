// XYEnvironment.cpp

#include "Environment/xyenv/include/XYEnvironment.h"

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

void XYEnvironment::addObjectToLocation(std::shared_ptr<EnvironmentObject> eo, XYLocation* loc)
{
    moveObjectToAbsoluteLocation(eo, loc);
}

void XYEnvironment::moveObjectToAbsoluteLocation(std::shared_ptr<EnvironmentObject> eo, XYLocation* loc)
{
    envState->moveObjectToAbsoluteLocation(eo, loc);
    //addEnvironmentObject(eo);
}

XYLocation* XYEnvironment::getCurrentLocationFor(std::shared_ptr<EnvironmentObject> eo)
{
    return envState->getCurrentLocationFor(eo);
}

std::vector<std::shared_ptr<EnvironmentObject>>* XYEnvironment::getObjectsAt(XYLocation* loc)
{
    return envState->getObjectsAt(loc);
}

std::vector<LocationPair>* XYEnvironment::get_vector()
{
    return envState->get_vector();
}


