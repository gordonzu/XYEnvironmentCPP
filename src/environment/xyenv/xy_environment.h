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

    bool                is_blocked(XYLocation& xy);
    bool                in_radius(unsigned rad, XYLocation& loca, XYLocation& locb);
    void                move_object(Object* eo, const XYLocation::Direction& dir);
    void                add_to(Object* eo, XYLocation& loc);
    //void                make_perimeter();
    XYLocation*         get_location(Object* eo);
    size_t              get_vector_size();
    size_t              get_set_size(XYLocation& xy);
    std::set<Object*>&  get_objects_near(Object* obj, unsigned);
    Vector&             get_vector();
    void                test_set();
    Vector::iterator    has_xy(XYLocation& xy);

private:
    unsigned                            width;
    unsigned                            height;
    xy::Matrix                          matrix;
    std::unique_ptr<std::set<Object*>>  near_set;
    std::unique_ptr<Object>             w1;
    std::unique_ptr<Object>             w2;
    std::unique_ptr<Object>             w3;
    std::unique_ptr<Object>             w4;
    std::unique_ptr<XYLocation>         loc1;
    std::unique_ptr<XYLocation>         loc2;
    std::unique_ptr<XYLocation>         loc3;
    std::unique_ptr<XYLocation>         loc4;
};
#endif


