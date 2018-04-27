// Created by gordonzu on 3/23/18.

#include "environment/xyenv/xy_environment_state.h"

namespace xy
{
    XYState::XYState(unsigned w, unsigned h)
    {
        for (unsigned x = 1; x <= w; ++x) {
            for (unsigned y = 1; y <= h; ++y) {
                std::unique_ptr<std::set<EnvironmentObject*>> myset =
                        std::make_unique<std::set<EnvironmentObject*>>();
                std::unique_ptr<XYLocation> myloc = std::make_unique<XYLocation>(x, y);
                vec.emplace_back(*myloc, *myset);
            }
        }
    }

    XYState::~XYState()
    {
        std::for_each(walls.begin(), walls.end(), [](Wall* w){ delete w; });
        std::for_each(locs.begin(), locs.end(), [](XYLocation* xy){ delete xy; });
    }

    void XYState::add_object(EnvironmentObject* obj, const XYLocation& xy)
    {
        check_for_object(obj);
        std::set<EnvironmentObject*>* theset = get_set(xy);

        // why am I checking the set AGAIN for the object?????
        /*if ((its = theset->find(obj)) != theset->end()) {
            theset->erase(its);
        }*/
        //std::cout << "Type of the eo: " << typeid(obj).name() << std::endl;
        theset->insert(obj);
    }

    void XYState::add_object(EnvironmentObject& obj, const XYLocation& xy)
    {
        check_for_object(&obj);
        std::set<EnvironmentObject*>* theset = get_set(xy);

        // why am I checking the set AGAIN for the object?????
        if ((its = theset->find(&obj)) != theset->end()) {
            theset->erase(its);
        }
        //std::cout << "Type of the eo: " << typeid(obj).name() << std::endl;
        theset->insert(&obj);
        //std::cout << "The set size after insertion: " << theset->size() << std::endl;
    }
    void XYState::check_for_object(EnvironmentObject *obj)
    {
        for (itv = vec.begin(); itv != vec.end(); ++itv) {
            if ((its = itv->second.find(obj)) != itv->second.end()) {
                itv->second.erase(its);
                break;
            }
        }
    }

    std::set<EnvironmentObject*>* XYState::get_set(const XYLocation& xy)
    {
        if (has_xy(xy) != get_vector().end()) {
            //std::cout << "Found the xy location, returning the vector..." << std::endl;
            return &(itv->second);
        }
        else {
            //std::cout << "The xy location not found, returning new vector of eo's..." << std::endl;
            set = std::make_unique<std::set<EnvironmentObject*>>();
            vec.emplace_back(xy, *set);
            return &((has_xy(xy))->second);
        }
    }

    Vector::iterator XYState::has_xy(const XYLocation& loc)
    {
        itv = std::find_if(
                XYState::get_vector().begin(),
                XYState::get_vector().end(),
                [loc](std::pair<XYLocation, std::set<EnvironmentObject*>>& mypair) {
                    return (mypair.first == loc);
                });
        return itv;
    }

    XYLocation* XYState::get_object_location(EnvironmentObject *obj)
    {
        for (itv = vec.begin(); itv != vec.end(); ++itv) {
            if ((its = itv->second.find(obj)) != itv->second.end()) {
                return &(itv->first);
            }
        }
        return nullptr;
    }

    XYLocation* XYState::get_object_location(EnvironmentObject& obj)
    {
        for (itv = vec.begin(); itv != vec.end(); ++itv) {
            if ((its = itv->second.find(&obj)) != itv->second.end()) {
                return &(itv->first);
            }
        }
        return nullptr;
    }

    void XYState::move_object(EnvironmentObject* obj, const XYLocation::Direction& dir)
    {
        XYLocation* temp = get_object_location(obj);

        if (temp != nullptr) {
            temp = temp->location_at(dir);
            if (!(is_blocked(*temp))) {
                add_object(obj, *temp);
            }
        }
    }

    void XYState::move_object(EnvironmentObject& obj, const XYLocation::Direction& dir)
    {
        XYLocation* temp = get_object_location(obj);

        if (temp != nullptr) {
            temp = temp->location_at(dir);
            if (!(is_blocked(*temp))) {
                add_object(obj, *temp);
            }
        }
    }

    bool XYState::is_blocked(const XYLocation& xy)
    {
        //std::cout << "-----------------------------------" << std::endl;
        //std::cout << "size of set_size()... " <<  set_size(xy) << std::endl;
        //std::cout << "-----------------------------------" << std::endl;

        for (auto& eo : *(get_set(xy))) {
            if (static_cast<Wall*>(eo)) {
                return true;
            } else {
                //std::cout << "eo's type: " << typeid(eo).name() << std::endl;
            }
        }

        //std::cout << "Returning FALSE..." << std::endl;
        return false;
    }

    std::vector<std::pair<XYLocation, std::set<EnvironmentObject*>>>& XYState::get_vector()
    {
        return vec;
    }

    size_t XYState::set_size(const XYLocation& xy)
    {
        return has_xy(xy)->second.size();
    }

    size_t XYState::vector_size()
    {
        return XYState::get_vector().size();
    }

    void XYState::perimeter(unsigned w, unsigned h)
    {
        for (unsigned i =0; i < w; ++i) {
            walls.emplace_back(new Wall());
            locs.emplace_back(new XYLocation(i, 0));

            walls.emplace_back(new Wall());
            locs.emplace_back(new XYLocation(i, h - 1));
        }

        for (unsigned i =0; i < h; ++i) {
            walls.emplace_back(new Wall());
            locs.emplace_back(new XYLocation(0, i));

            walls.emplace_back(new Wall());
            locs.emplace_back(new XYLocation(w - 1, i));
        }

        std::vector<Wall*>::iterator itw = walls.begin();
        std::vector<XYLocation*>::iterator itx = locs.begin();

        while (itw != walls.end()) {
            add_object(**itw, **itx);
            ++itw;
            ++itx;
        }
    }
}

