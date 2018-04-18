//
// Created by gordonzu on 4/16/18.
//

#ifndef AICPP_BASE_ACTION_H
#define AICPP_BASE_ACTION_H

#include "dynamic_attributes.h"

class BaseAction {
public:
    virtual ~BaseAction()=default;
    virtual bool is_no_op()=0;
};

class DynamicAction: public virtual BaseAction, public virtual DynamicAttributes {
public:
    static constexpr const char* ATTRIBUTE_NAME = "name";

    explicit DynamicAction(const char* name);
    ~DynamicAction() override =default;
    bool operator==(DynamicAction&);
    bool is_no_op() override;
};



class NoOpAction: public DynamicAction {
    //NoOpAction();
    //NoOpAction(const NoOpAction&)=delete;
    //NoOpAction& operator=(const NoOpAction&)=delete;

public:
    NoOpAction();
    ~NoOpAction() override =default;
    bool operator==(const NoOpAction&) const;
    bool is_no_op() override;
    static const NoOpAction& NoOp();
};


#endif //AICPP_BASE_ACTION_H
