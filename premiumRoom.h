#pragma once

#ifndef PREMIUM_ROOM_H
#define PREMIUM_ROOM_H

#include "room.h"

class PremiumRoom : public Room
{
private:
    bool is_smoking;

    const static bool default_is_smoking;

public:
    PremiumRoom(){};
    PremiumRoom(int, bool, const int = default_capacity, const status = default_status, const bed_type = default_bed_type,
                const time_t = default_check_in_date, const time_t = default_check_out_date,
                const string = default_staff_in_charge, const string = default_name_occ, const double = default_price, const bool = default_is_smoking);

    PremiumRoom addRoom(int);
    void displayRoom();

    void setIsSmoking(bool);
    bool getIsSmoking() const;
};

#endif
