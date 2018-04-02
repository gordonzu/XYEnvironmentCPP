// EnvironmentObject .cpp
//

#include <iostream>
#include "object.h"


Object::~Object()
{
}


char* Wall::talk() {
    return const_cast<char *>("Wall...");

}



