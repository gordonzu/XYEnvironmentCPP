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
    ~DynamicAction() override =default;
    bool operator==(DynamicAction&);
    bool is_no_op() const override;
    static std::unique_ptr<DynamicAction> DynamicPtr();
};



class NoOpAction: public DynamicAction {
public:
    NoOpAction();
    ~NoOpAction() override =default;
    bool operator==(const NoOpAction&) const;
    bool is_no_op() const override;
    static const NoOpAction& NoOp();
    static std::unique_ptr<NoOpAction> NoOpPtr();
};

#endif //AICPP_BASE_ACTION_H