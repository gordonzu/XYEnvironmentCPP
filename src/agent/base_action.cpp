//
// Created by gordonzu on 4/16/18.
//

#include "base_action.h"

constexpr const char* DynamicAction::ATTRIBUTE_NAME;

DynamicAction::DynamicAction(const char* name) {
        set_attribute(ATTRIBUTE_NAME, name);
}

bool DynamicAction::is_no_op() {
    return false;
}

bool DynamicAction::operator==(DynamicAction& lhs) {
    return ((this->get_attribute(ATTRIBUTE_NAME)) == (lhs.get_attribute(ATTRIBUTE_NAME)));
}

NoOpAction::NoOpAction(): DynamicAction{"NoOp"} {
}

bool NoOpAction::is_no_op() {
    return false;
}

const NoOpAction& NoOpAction::NoOp() {
    static const NoOpAction _instance;
    return _instance;
}

bool NoOpAction::operator==(const NoOpAction& lhs) const {
    return ((this->get_attribute(ATTRIBUTE_NAME)) == (lhs.get_attribute(ATTRIBUTE_NAME)));
}




