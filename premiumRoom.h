#pragma once

#ifndef PREMIUM_ROOM_H
#define PREMIUM_ROOM_H

#include "room.h"

class PremiumRoom : virtual public Room
{
private:
    bool is_smoking;

public:
    const static bool default_is_smoking;

    PremiumRoom(){};
    PremiumRoom(int, bool, const int = default_capacity, const room_status = default_status, const bed_type = default_bed_type,
                const string = default_staff_in_charge, const string = default_name_occ, const double = default_price, const bool = default_is_smoking);

    PremiumRoom addRoom(int);
    void displayRoom();

    void setIsSmoking(bool);
    bool getIsSmoking() const;

    PremiumRoom operator*(double);

};

#endif
