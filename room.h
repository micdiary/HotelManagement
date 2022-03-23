#pragma once

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

using namespace std;

enum class status
{
    status_clean = 0,
    status_booked,
    status_in_use,
    status_maintenance
};

enum class bed_type
{
    bed_type_single,
    bed_type_double,
    bed_type_master
};

class Room
{
private:
    int room_number;
    status st;
    bed_type bed;
    time_t check_in_date;
    time_t check_out_date;
    bool is_wifi;
    string staff_in_charge;
    double price;
    int capacity;

    const static status default_status;
    const static double default_price;
    const static bool default_is_smoking;
    const static bool default_is_wifi;

public:
    Room(){};
    Room(const status default_status,const double default_price, const bool default_is_smoking, const bool default_is_wifi);
    void search(int);
    // class Customer cust;
    Room addRoom(int);

    void deleteRoom(int);
    void displayRoom(Room);

    // bool getIsWifi();
    // void setIsWifi();
    bool getIsSmoking();
    void setIsSmoking();

    int getCapacity();
    void setCapacity(int);
    // bool getIsWifi();
    // void setIsWifi();
};
#endif
