#pragma once

#ifndef HOTEL_MANAGEMENT_H
#define HOTEL_MANAGEMENT_H

#include <string>

#include "staff.h"

using namespace std;

class HotelManagement
{
public:
    void manageRooms(Array<Staff>, Array<Staff>);
    void checkIn();
    void addRoomsOption();
    
};
#endif
