#ifndef XYLOCATION_H 
#define XYLOCATION_H

#include <iostream>

class XYLocation {
public:
    XYLocation(int w, int h);
    void xylocation(); 
    bool operator==(const XYLocation& rhs) const; 

private:
    int width_;
    int height_;
};
#endif

