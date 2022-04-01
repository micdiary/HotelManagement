#pragma once

#ifndef COMMON_H
#define COMMON_H

#include <string>
#include "room.h"
#include "premiumRoom.h"
#include "doubleRoom.h"
#include "vipRoom.h"
#include "customer.h"

using namespace std;

// acts as pointer
extern int NO_OF_ROOMS;
extern Room rooms[50];
extern PremiumRoom premium_rooms[50];
extern DoubleRoom double_rooms[50];
extern VipRoom vip_rooms[50];

extern int NO_OF_CUSTOMERS;
extern Customer customers[50];

extern string RESERVATION_CODE;

#endif
