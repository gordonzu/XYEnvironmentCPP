// EnvironmentObject .cpp
//

#include <iostream>
#include "object.h"


Object::~Object()
{
}

char* Agent::talk() {
    return const_cast<char *>("Agent...");
}

char* Wall::talk() {
    return const_cast<char *>("Wall...");

}



