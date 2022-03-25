#pragma once

#ifndef ROOM_H
#define ROOM_H

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
    bool is_wifi;
    int capacity;

    status st;
    bed_type bed;
    time_t check_in_date;
    time_t check_out_date;
    string staff_in_charge;
    string name_occ;
    double price;

    const static status default_status;
    const static bed_type default_bed_type;
    const static time_t default_check_in_date;
    const static time_t default_check_out_date;
    const static double default_price;
    const static string default_staff_in_charge;
    const static string default_name_occ;

    const static bool default_is_smoking;
    const static bool default_is_wifi;


public:
    Room(){};
    Room(int, bool, int, const status = default_status, const bed_type = default_bed_type,
         const time_t = default_check_in_date, const time_t = default_check_out_date,
         const string = default_staff_in_charge, const string = default_name_occ, const double = default_price);
    void search(int);
    // class Customer cust;
    Room addRoom(int);

    // void deleteRoom(int);

    void displayRoom();

    int getRoomNo();
    void setRoomNo(int);

    status getRoomStatus();
    void setRoomStatus(status);

    bed_type getBedType();
    void setBedType(bed_type);

    time_t getCheckInDate();
    void setCheckInDate(time_t);

    time_t getCheckOutDate();
    void setCheckOutDate(time_t);

    bool getIsSmoking();
    void setIsSmoking(bool);

    bool getStaffInCharge();
    void setStaffInCharge(string);

    int getCapacity();
    void setCapacity(int);

    int getPrice();
    void setPrice(double);

    string getNameOcc();
    void setNameOcc(string);

    bool getIsWifi();
    void setIsWifi(bool);
};
#endif
