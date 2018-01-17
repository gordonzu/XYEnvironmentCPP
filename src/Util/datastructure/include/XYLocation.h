#ifndef XYLOCATION_H 
#define XYLOCATION_H

#include <iostream>

class XYLocation {
public:
    XYLocation(int x, int y);
    void xylocation();

    enum class Direction: unsigned short{ NORTH, SOUTH, EAST, WEST };

    int getx();
    int gety();
    XYLocation* west();
    XYLocation* east();
    XYLocation* north();
    XYLocation* south();
    XYLocation* left();
    XYLocation* right();
    XYLocation* up();
    XYLocation* down();
    XYLocation* locationAt(Direction& direction);
 
    bool operator==(const XYLocation& rhs) const; 

private:
    int x_;
    int y_;
};
#endif

