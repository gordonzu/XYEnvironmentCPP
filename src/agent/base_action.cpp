//
// Created by gordonzu on 4/16/18.
//

#include "base_action.h"

//TODO -- constructor parameter needs to be shared_ptr<const char*>
//TODO -- static const char* ATTRIBUTE_NAME needs to be a shared_ptr<const char*>

constexpr const char* DynamicAction::ATTRIBUTE_NAME;

DynamicAction::DynamicAction()
{
}

DynamicAction::DynamicAction(const char* name)
{
        set_attribute(ATTRIBUTE_NAME, name);
}

bool DynamicAction::is_no_op() const
{
    return false;
}

bool DynamicAction::operator==(const DynamicAction& lhs) const
{
    return ((this->get_attribute(ATTRIBUTE_NAME)) == (lhs.get_attribute(ATTRIBUTE_NAME)));
}

DynamicAction* DynamicAction::DynamicPtr()
{
    static DynamicAction instance;
    return &instance;
}

NoOpAction::NoOpAction(): DynamicAction{"NoOp"}
{
}

bool NoOpAction::is_no_op() const
{
    return true;
}

const NoOpAction& NoOpAction::NoOp()
{
    static const NoOpAction _instance;
    return _instance;
}

NoOpAction* NoOpAction::NoOpPtr()
{
    static NoOpAction instance;
    return &instance;
}

bool NoOpAction::operator==(const NoOpAction& lhs) const
{
    return ((this->get_attribute(ATTRIBUTE_NAME)) == (lhs.get_attribute(ATTRIBUTE_NAME)));
}




