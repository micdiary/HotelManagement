#pragma once

#ifndef DOUBLE_ROOM_H
#define DOUBLE_ROOM_H

#include "room.h"

class DoubleRoom : virtual public Room
{
public:
    DoubleRoom(){};
    DoubleRoom(int, bool, const int = default_capacity, const room_status = default_status,
             const string = default_name_occ, const double = default_price);

    DoubleRoom addRoom(int);
    void displayRoom();

    DoubleRoom operator*(double);
    
};

#endif
