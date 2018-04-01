//

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

    bool                is_blocked(const XYLocation& xy);
    bool                is_blocked(const XYLocation&& xy);
    bool                in_radius(unsigned rad, const XYLocation& loca, const XYLocation& locb);
    void                move_object(Object* eo, const XYLocation::Direction& dir);
    void                add_to(Object* eo, const XYLocation& loc);
    void                make_perimeter();
    XYLocation*         get_location(Object* eo);
    size_t              get_vector_size();
    size_t              get_set_size(const XYLocation& xy);
    std::set<Object*>&  get_objects_near(Object* obj, unsigned);
    Vector&             get_vector();

private:
    unsigned                                    width;
    unsigned                                    height;
    xy::Matrix                                  matrix;
    std::unique_ptr<std::set<Object*>>          near_set;
};
#endif


