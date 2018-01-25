#ifndef XYLOCATION_H 
#define XYLOCATION_H

#include <iostream>
#include <memory>

class XYLocation {
public:
    XYLocation();
    XYLocation(int x, int y);
    XYLocation(XYLocation&& other);
    ~XYLocation();
    XYLocation(const XYLocation& other);

    XYLocation& operator=(const XYLocation& rhs);
    bool operator==(const XYLocation& rhs) const; 
    bool operator<(const XYLocation& rhs) const;

    void print();
    enum class Direction: unsigned short{ NORTH, SOUTH, EAST, WEST };

    int getx();
    int gety();

    std::shared_ptr<XYLocation> west();
    std::shared_ptr<XYLocation> east();
    std::shared_ptr<XYLocation> north();
    std::shared_ptr<XYLocation> south();
    std::shared_ptr<XYLocation> left();
    std::shared_ptr<XYLocation> right();
    std::shared_ptr<XYLocation> up();
    std::shared_ptr<XYLocation> down();
    std::shared_ptr<XYLocation> location_at(const Direction& direction);

private:
    int x_;
    int y_;
};
#endif

