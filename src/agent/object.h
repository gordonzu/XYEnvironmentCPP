#ifndef ENVIRONMENT_OBJECT_H
#define ENVIRONMENT_OBJECT_H

class Object {
public:
    virtual ~Object()=0;
    virtual char* talk()=0;
};

class Agent: public Object {
public:
    virtual ~Agent() {}
    virtual char* talk();
};

class Wall: public Object {
public:
    virtual ~Wall() {}
    virtual char* talk();
};

#endif


