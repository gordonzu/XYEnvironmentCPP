//
// Created by gordonzu on 4/16/18.
//

#ifndef AICPP_BASE_ACTION_H
#define AICPP_BASE_ACTION_H

#include "dynamic_attributes.h"

class BaseAction {
public:
    virtual ~BaseAction()=default;
    virtual bool is_no_op() const =0;
};

class DynamicAction: public virtual BaseAction, public virtual DynamicAttributes {
public:
    static constexpr const char* ATTRIBUTE_NAME = "name";

    DynamicAction();
    explicit DynamicAction(const char* name);
    virtual ~DynamicAction() override =default;
    bool operator==(const DynamicAction&) const;
    bool is_no_op() const override;
    static DynamicAction* DynamicPtr();
};

class NoOpAction: public DynamicAction {
public:
    NoOpAction();
    ~NoOpAction() override =default;
    bool operator==(const NoOpAction&) const;
    bool is_no_op() const override;
    static const NoOpAction& NoOp();
    static NoOpAction* NoOpPtr();
};

#endif //AICPP_BASE_ACTION_H

//TODO: have both action classes inherit from base_action and dynamicAttributes
//TODO: Better yet, have dynamic attributes contained in the base class and have both
//TODO: derived actions inherit from simply the single base.
