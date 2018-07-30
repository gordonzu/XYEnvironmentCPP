// Created by gordonzu on 7/30/18.

#ifndef AICPP_KEYVALUE_OBJECT_H
#define AICPP_KEYVALUE_OBJECT_H

#include <string>

class KVObject
{
public:
    KVObject() =default;
    virtual ~KVObject() =default;
    std::string print() =0;
};

class String: public KVObject
{    
public:
    String() =default;
    virtual ~String() =default;
    std::string print() override;

private:
    std::string strrep;
};

class Bool: public KVObject
{
public:
    Bool() =default;
    virtual ~Bool() =default;
    std::string print() override;

private:
    std::string strrep;
#endif


