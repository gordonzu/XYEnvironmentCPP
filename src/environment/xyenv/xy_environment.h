#ifndef XY_ENVIRONMENT_H
#define XY_ENVIRONMENT_H

#include <vector>
#include <memory>
#include "agent/environment.h"
#include "util/datastructure/xy_location.h"

using VectorOfPairs = std::vector<std::pair<XYLocation, std::vector<Object*>>>;

class XYEnvironment: public Environment {
public:
    XYEnvironment(); 
    XYEnvironment(int w, int h); 
    virtual ~XYEnvironment();

    void                                move_object(Object* eo, const XYLocation::Direction& dir);
    void                                add_to(Object* eo, XYLocation& loc); 
    bool                                is_blocked(XYLocation& loc);
    //std::shared_ptr<XYLocation>         get_location(Object* eo); 
    XYLocation*                         get_location(Object* eo); 
    std::vector<Object*>&               get_at(XYLocation& loc);

    std::vector<std::pair<XYLocation,std::vector<Object*>>>& get_vector();

private:
    int                                                 width_;
    int                                                 height_;
    VectorOfPairs                                       vecPairs;
    std::unique_ptr<std::vector<Object*>>               env_vector;
    Object*                                             env_ptr;
    std::unique_ptr<XYLocation>                         xyuniq;
};
#endif


