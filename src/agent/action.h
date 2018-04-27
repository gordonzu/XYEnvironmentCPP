//
// Created by gordonzu on 4/16/18.
//

#ifndef AICPP_BASE_ACTION_H
#define AICPP_BASE_ACTION_H

#include "dynamic_object.h"

namespace ag {

    class Action : public DynamicObject
    {
    public:
        static constexpr const char *ATTRIBUTE_NAME = "name";
        Action();
        explicit Action(const char *name);
        virtual ~Action() override = default;
        bool operator==(const Action &) const;
        virtual bool is_no_op() const;
        static Action *DynamicPtr();
    };

    class NoOpAction : public Action
    {
    public:
        NoOpAction();
        ~NoOpAction() override = default;
        bool operator==(const NoOpAction &) const;
        bool is_no_op() const override;
        static const NoOpAction &NoOp();
        static NoOpAction *NoOpPtr();
    };
}
#endif //AICPP_BASE_ACTION_H

//TODO: have both action classes inherit from base_action and dynamicAttributes
//TODO: Better yet, have dynamic attributes contained in the base class and have both
//TODO: derived actions inherit from simply the single base.

//TODO: This for both Actions and Percepts -- DynamicAttributes has to be THE base class for both
//TODO: How about a DynamicObject base class for both... DynamicObject from Object?
