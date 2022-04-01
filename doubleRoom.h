#pragma once

#ifndef DOUBLE_ROOM_H
#define DOUBLE_ROOM_H

#include "room.h"

class DoubleRoom : virtual public Room
{
public:
    DoubleRoom(){};
    DoubleRoom(int, bool, const int = default_capacity, const room_status = default_status, const bed_type = default_bed_type,
                const string = default_staff_in_charge, const string = default_name_occ, const double = default_price);

    DoubleRoom addRoom(int);
    void displayRoom();

    // void setCapacity(int);
    // int getCapacity() const;

    DoubleRoom operator*(double);
    
};

#endif