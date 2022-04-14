#pragma once

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

#include "staff.h"

using namespace std;

enum class reservation_status
{
    reservation_confirm,
    reservation_wait_list,
    reservation_expire
};

enum class room_type
{
    room_base,
    room_double,
    room_premium,
    room_vip
};

class Customer
{
private:
    string name;
    int room_number;
    room_type r_type;
    reservation_status reservation;
    string reservation_code;
    string cleaner_in_charge;
    string manager_in_charge;

public:
    Customer(){};
    Customer(string, int, room_type, reservation_status, string);

    void search(int);
    int registerCustomer();
    void payFees(int);

    string getName();
    void setName(string);

    int getRoomNumber();
    void setRoomNumber(int);

    reservation_status getReservationStatus();
    void setReservationStatus(reservation_status);

    string getReservationCode();
    void setReservationCode(string);

    room_type getRoomType();
    void setRoomType(room_type);

    void setCleanerincharge(string);
    string getCleanerincharge();

    void setManagerincharge(string);
    string getManagerincharge();
};
#endif
