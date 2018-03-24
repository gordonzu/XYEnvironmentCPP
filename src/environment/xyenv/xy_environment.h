#ifndef XY_ENVIRONMENT_H
#define XY_ENVIRONMENT_H

#include <memory>
#include "agent/environment.h"
#include "util/datastructure/xy_location.h"
#include "util/datastructure/matrix.h"

class XYEnvironment: public Environment {
public:
    XYEnvironment() = delete;
    XYEnvironment(unsigned w, unsigned h);
    virtual ~XYEnvironment();

    void        move_object(Object* eo, const XYLocation::Direction& dir);
    void        add_to(Object* eo, XYLocation& loc);
    XYLocation* get_location(Object* eo);
    size_t      get_vector_size();
    size_t      get_set_size(XYLocation& xy);

private:
    xy::Matrix  matrix;
};
#endif


