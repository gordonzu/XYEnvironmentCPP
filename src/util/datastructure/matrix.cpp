// Created by gordonzu on 3/23/18.

#include "matrix.h"

namespace xy {

    Matrix::Matrix(unsigned w, unsigned h) {
        for (unsigned x = 1; x <= w; ++x) {
            for (unsigned y = 1; y <= h; ++y) {
                vec.emplace_back(XYLocation(x, y), std::set<Object*>());
            }
        }
    }

    Matrix::~Matrix() = default;

    void Matrix::add_object(Object* obj, XYLocation& xy) {
        check_for_object(obj);
        std::set<Object*>* theset = get_set(xy);

        if ((its = theset->find(obj)) != theset->end()) {
            theset->erase(its);
        }
        theset->insert(obj);
    }

    void Matrix::check_for_object(Object *obj) {
        for (itv = vec.begin(); itv != vec.end(); ++itv) {
            if ((its = itv->second.find(obj)) != itv->second.end()) {
                itv->second.erase(its);
                break;
            }
        }
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

    Vector::iterator Matrix::has_xy(XYLocation& loc) {
        itv = std::find_if(
                Matrix::get_vector().begin(),
                Matrix::get_vector().end(),
                [loc](std::pair<XYLocation, std::set<Object*>>& mypair) {
                    return (mypair.first == loc);
                });
        return itv;
    }

    XYLocation* Matrix::get_object_location(Object *obj) {
        for (itv = vec.begin(); itv != vec.end(); ++itv) {
            if ((its = itv->second.find(obj)) != itv->second.end()) {
                return &(itv->first);
            }
        }
        return nullptr;
    }

    void Matrix::move_object(Object* obj, const XYLocation::Direction& dir) {
        XYLocation* temp = get_object_location(obj);

        if (temp != nullptr) {
            temp = temp->location_at(dir);
            if (!(is_blocked(*temp))) {
                add_object(obj, *temp);
            }
        }
    }

    bool Matrix::is_blocked(XYLocation& xy) {
        for (auto& eo : *(get_set(xy))) {
            if (dynamic_cast<Wall*>(eo)) {
                return true;
            }
        }
        return false;
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

