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

void XYEnvironment::addObjectToLocation(PtrEnv eo, std::shared_ptr<XYLocation> loc)
{
    moveObjectToAbsoluteLocation(eo, loc);
}

void XYEnvironment::moveObjectToAbsoluteLocation(PtrEnv eo, std::shared_ptr<XYLocation> loc)
{
    envState->moveObjectToAbsoluteLocation(eo, loc);
    addEnvironmentObject(eo);
}

std::shared_ptr<XYLocation> XYEnvironment::getCurrentLocationFor(PtrEnv eo)
{
    return envState->getCurrentLocationFor(eo);
}

std::vector<PtrEnv>& XYEnvironment::getObjectsAt(std::shared_ptr<XYLocation> loc)
{
    return envState->getObjectsAt(loc);
}

std::vector<LocationPair>& XYEnvironment::get_vector()
{
    return envState->get_vector();
}

PtrEnv XYEnvironment::get_pointer()
{
    return envState->get_pointer();
}


