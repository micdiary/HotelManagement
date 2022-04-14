#pragma once

#ifndef VIP_ROOM_H
#define VIP_ROOM_H

#include "premiumRoom.h"
#include "doubleRoom.h"

class VipRoom : public PremiumRoom, public DoubleRoom
{
private:
    bool is_smoking;

public:
    const static bool default_is_smoking;

    VipRoom(){};
    VipRoom(int, bool, const int = default_capacity, const room_status = default_status,
            const string = default_name_occ, const double = default_price, const bool = default_is_smoking);

    VipRoom addRoom(int);
    void displayRoom();

    void setIsSmoking(bool);
    bool getIsSmoking() const;

    VipRoom operator*(double);
    VipRoom operator+(int);
};

#endif
