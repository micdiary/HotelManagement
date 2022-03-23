#include <stdexcept>
#include "premiumRoom.h"

PremiumRoom::PremiumRoom(bool smoking) : Room()
{
    setIsSmoking(smoking);
}

void PremiumRoom::setIsSmoking(bool smoking)
{
    is_smoking = smoking;
}

bool PremiumRoom::getIsSmoking() const
{
    return is_smoking;
}
