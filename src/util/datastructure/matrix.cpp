// Created by gordonzu on 3/23/18.

#include "matrix.h"

namespace xy {

    Vector Matrix::vec = Vector();

    Matrix::Matrix(unsigned w, unsigned h) {
        for (unsigned x = 1; x <= w; ++x) {
            for (unsigned y = 1; y <= h; ++y) {
                vec.emplace_back(XYLocation(x, y), std::set<Object*>());
            }
        }
    }

    Matrix::~Matrix() = default;

    Vector::iterator Matrix::has_xy(XYLocation& loc) {
        itv = std::find_if(
                Matrix::get_vector().begin(),
                Matrix::get_vector().end(),
                [loc](std::pair<XYLocation, std::set<Object*>>& mypair) {
                    return (mypair.first == loc);
                });
        return itv;
    }

    bool Matrix::add_object(Object* obj, XYLocation& xy) {
        std::set<Object*>* theset = get_set(xy);

        if (theset) {
            if ((its = theset->find(obj)) != theset->end()) {
                theset->erase(its);
            }
            theset->insert(obj);
            return true;
        }
        else
            return false;
    }

    XYLocation* Matrix::get_object_location(Object *obj)
    {
        for (itv = vec.begin(); itv != vec.end(); ++itv) {
            if ((its = itv->second.find(obj)) != itv->second.end()) {
                return &(itv->first);
            }
        }
        return nullptr;
    }

    std::set<Object*>* Matrix::get_set(XYLocation& xy) {
        if (has_xy(xy) != get_vector().end()) {
            return &(itv->second);
        }
        else {
            set = std::make_unique<std::set<Object*>>();
            vec.emplace_back(xy, *set);
            return set.get();
        }
    }

    std::vector<std::pair<XYLocation, std::set<Object*>>>& Matrix::get_vector() {
        return vec;
    }

    size_t Matrix::set_size(XYLocation& xy) {
        return get_set(xy)->size();
    }

    size_t Matrix::vector_size() {
        return Matrix::get_vector().size();
    }
}

