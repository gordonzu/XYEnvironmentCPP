//
// Created by gordonzu on 4/15/18.
//

#ifndef ENVIRONMENT_OBJECT_H
#define ENVIRONMENT_OBJECT_H

class Object {
protected:
    Object()=default;
public:
    virtual ~Object()=default;
    virtual const char* talk()=0;
};


class Wall: public Object {
public:
    ~Wall() override =default;
    virtual const char* talk() { return "Wall..."; }
};

#endif //AICPP_OBJECT_H
