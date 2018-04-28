//
// Created by gordonzu on 4/16/18.
//

#include "action.h"
namespace ag {
    constexpr const char *Action::ATTRIBUTE_NAME;

    Action::Action() {
    }

    Action::Action(const char *name) {
        set_attribute(ATTRIBUTE_NAME, name);
    }

    bool Action::is_no_op() const {
        return false;
    }

    bool Action::operator==(const Action &lhs) const {
        return ((this->get_attribute(ATTRIBUTE_NAME)) == (lhs.get_attribute(ATTRIBUTE_NAME)));
    }

    Action *Action::DynamicPtr() {
        static Action instance;
        return &instance;
    }

    std::string Action::string()
    {
        std::string out;
        out.append("Action[");
        out.append(Action::ATTRIBUTE_NAME);
        out.append("=");
        out.append(this->get_attribute(Action::ATTRIBUTE_NAME));
        out.append("]");
        return out;
    }

    NoOpAction::NoOpAction() : Action{"NoOp"} {
    }

    bool NoOpAction::is_no_op() const {
        return true;
    }

    const NoOpAction &NoOpAction::NoOp() {
        static const NoOpAction _instance;
        return _instance;
    }

    NoOpAction *NoOpAction::NoOpPtr() {
        static NoOpAction instance;
        return &instance;
    }

    bool NoOpAction::operator==(const NoOpAction &lhs) const {
        return ((this->get_attribute(ATTRIBUTE_NAME)) == (lhs.get_attribute(ATTRIBUTE_NAME)));
    }

}


