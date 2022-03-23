#pragma once

#ifndef OVERNIGHT_H
#define OVERNIGHT_H

#include "room.h"

class PremiumRoom : public Room
{
private:
    bool is_smoking;
public:
    PremiumRoom(bool);

    void setIsSmoking(bool);
    bool getIsSmoking() const;
};

#endif
