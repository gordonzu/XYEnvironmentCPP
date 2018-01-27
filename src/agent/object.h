#ifndef ENVIRONMENT_OBJECT_H
#define ENVIRONMENT_OBJECT_H

class Object {
public:
    virtual ~Object()=0;
};

class Agent: public Object {
public:
    virtual ~Agent() {}
};

class Wall: public Object {
public:
    virtual ~Wall() {}
};

#endif


