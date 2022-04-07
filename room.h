#pragma once

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "customer.h"
using namespace std;

enum class room_status
{
    status_clean,
    status_booked,
    status_in_use,
    status_maintenance
};

class Room
{
private:
    int room_number;
    bool is_wifi;

    int capacity;
    room_status st;
    string name_occ;
    double price;

public:
    const static int default_capacity;
    const static room_status default_status;
    const static double default_price;
    const static string default_name_occ;

    const static bool default_is_smoking;
    const static bool default_is_wifi;

    Room(){};
    Room(int, bool, const int = default_capacity, const room_status = default_status,
         const string = default_name_occ, const double = default_price);
    Room addRoom(int);

    bool checkPayment(string);

    string checkIn(int, string, room_type);
    void checkOut(int, room_type);

    void displayRoom();
    void getAvailRoom();

    int getRoomNo();
    void setRoomNo(int);

    room_status getRoomStatus();
    void setRoomStatus(room_status);

    int getCapacity();
    void setCapacity(int);

    double getPrice();
    void setPrice(double);

    string getNameOcc();
    void setNameOcc(string);

    bool getIsWifi();
    void setIsWifi(bool);

    Room operator*(double);

    friend ostream & operator << (ostream &out, const Room &r);
};
#endif
