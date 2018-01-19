#ifndef XYLOCATION_H 
#define XYLOCATION_H

#include <iostream>
#include <memory>

class XYLocation {
public:
    XYLocation(int x, int y);
    ~XYLocation();

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
    std::shared_ptr<XYLocation> locationAt(const Direction& direction);
 
    bool operator==(const XYLocation& rhs) const; 

private:
    int x_;
    int y_;
};
#endif

