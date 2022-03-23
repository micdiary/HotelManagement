#pragma once

#ifndef COMMON_H
#define COMMON_H

#include <string>
#include "room.h"

using namespace std;

// acts as pointer
extern int NO_OF_ROOMS;
extern Room rooms[50];

class Common
{
public:
    int NO_OF_GUESTS = 0;
    
};
#endif
