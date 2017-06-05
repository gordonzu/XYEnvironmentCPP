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

std::vector<EnvironmentObject*>* XYEnvironment::getObjectsAt(XYLocation* loc)
{
    return envState->getObjectsAt(loc);
}

std::vector<LocationPair>* XYEnvironment::get_vector()
{
    return envState->get_vector();
}


