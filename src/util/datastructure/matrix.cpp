// Created by gordonzu on 3/23/18.

#include "matrix.h"

namespace xy {

    Vector Matrix::vec = Vector();

    // constructor builds matrix w rows wide and h columns high
    Matrix::Matrix(unsigned w, unsigned h) {
        for (unsigned x = 1; x <= w; ++x) {
            for (unsigned y = 1; y <= h; ++y) {
                vec.emplace_back(XYLocation(x, y), std::set<Object*>());
            }
        }
    }

    // default destructor
    Matrix::~Matrix() = default;

    // searches the vector for a given XYLocation. Returns an index position.
    Vector::iterator Matrix::has_xy(XYLocation& loc) {
        it = std::find_if(
                Matrix::get_vector().begin(),
                Matrix::get_vector().end(),
                [loc](std::pair<XYLocation, std::set<Object*>>& mypair) {
                    return (mypair.first == loc);
                });
        return it;
    }

    // adds a polymorphic agent pointer to the set corresponding to a given XYLocation. Returns a boolean.
    bool Matrix::add_object(Object* obj, XYLocation& xy) {
        std::set<Object*>::iterator myit;
        std::set<Object*>* theset = get_set(xy);

        if (theset) {
            if ((myit = theset->find(obj)) != theset->end()) {
                theset->erase(myit);
            }
            theset->insert(obj);
            return true;
        }
        else
            return false;
    }

    std::set<Object*>* Matrix::get_set(XYLocation& xy) {
        if (has_xy(xy) != get_vector().end()) {
            return &(*it).second;
        }
        else {
            return nullptr;
        }
    }

    std::vector<std::pair<XYLocation, std::set<Object*>>>& Matrix::get_vector() {
        return vec;
    }

    size_t Matrix::set_size(XYLocation& xy) {
        if (get_set(xy)) {
            return get_set(xy)->size();
        }
        else
            return 0;
    }

    size_t Matrix::vector_size() {
        return Matrix::get_vector().size();
    }

}

