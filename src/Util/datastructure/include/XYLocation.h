#ifndef XYLOCATION_H 
#define XYLOCATION_H

#include <iostream>
#include <memory>

class XYLocation {
public:
    XYLocation(); 
    XYLocation(int x, int y);

    enum class Direction: unsigned short{ NORTH, SOUTH, EAST, WEST };
    int getx();
    int gety();
    void print();
//    XYLocation* west();
//    XYLocation* east();
//    XYLocation* north();
    void north();
//    XYLocation* south();
//    XYLocation* left();
//    XYLocation* right();
//    XYLocation* up();
//    XYLocation* down();
    //XYLocation* locationAt(const Direction& direction);
    void locationAt(const Direction& direction);
    bool operator==(const XYLocation& rhs) const; 

private:
    int x_;
    int y_;
};
#endif

