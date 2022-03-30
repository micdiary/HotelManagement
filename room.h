#pragma once

#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;

enum class status
{
    status_clean,
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
    string staff_in_charge;
    string name_occ;
    double price;

public:
    const static int default_capacity;
    const static status default_status;
    const static bed_type default_bed_type;
    const static double default_price;
    const static string default_staff_in_charge;
    const static string default_name_occ;

    const static bool default_is_smoking;
    const static bool default_is_wifi;

    Room(){};
    Room(int, bool, const int = default_capacity, const status = default_status, const bed_type = default_bed_type,
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

    // bool getIsSmoking();
    // void setIsSmoking(bool);

    string getStaffInCharge();
    void setStaffInCharge(string);

    int getCapacity();
    void setCapacity(int);

    double getPrice();
    void setPrice(double);

    string getNameOcc();
    void setNameOcc(string);

    bool getIsWifi();
    void setIsWifi(bool);
};
#endif
