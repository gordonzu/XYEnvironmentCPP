#ifndef XY_ENVIRONMENT_H
#define XY_ENVIRONMENT_H

//#include <vector>
#include <memory>
#include "agent/environment.h"
#include "util/datastructure/xy_location.h"
#include "util/datastructure/matrix.h"

//using Vector = std::vector<std::pair<XYLocation, std::vector<Object*>>>;

class XYEnvironment: public Environment {
public:
    XYEnvironment() = delete;
    XYEnvironment(unsigned w, unsigned h);
    virtual ~XYEnvironment();

//    void                                move_object(Object* eo, const XYLocation::Direction& dir);
//    void                                add_to(Object* eo, XYLocation& loc);
//    bool                                is_blocked(XYLocation& loc);
//    XYLocation*                         get_location(Object* eo);
//    std::vector<Object*>&               get_at(XYLocation& loc);
//    Vector&                             get_vector();
    xy::Matrix&                           get_matrix();

private:
    xy::Matrix                                  matrix;
    //int                                                 width_;
    //int                                                 height_;
    //Vector                                              vec_pairs;
    //std::unique_ptr<XYLocation>                         xyuniq;
    //std::unique_ptr<std::vector<Object*>>               vec_objs;
};
#endif


