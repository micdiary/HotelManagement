#include <iostream>

#include "common.h"
#include "room.h"
#include <ctime>

Room::Room(int room_number, bool is_wifi, int capacity,
           status status, bed_type bed_type,
           time_t check_in_date, time_t check_out_date,
           string staff_in_charge, string name_occ, double price)
{
    this->room_number = room_number;
    this->is_wifi = is_wifi;
    this->capacity = capacity;
    this->st = status;
    this->bed = bed_type;
    this->check_in_date = check_in_date;
    this->check_out_date = check_out_date;
    this->staff_in_charge = staff_in_charge;
    this->name_occ = name_occ;
    this->price = price;
}

Room Room::addRoom(int rno)
{
    bool wifi;
    int capacity;

    cout << "\nWifi (0 = false, 1 = true): ";
    cin >> wifi;

    cout << "\nCapacity: ";
    cin >> capacity;

    Room room(rno, wifi, capacity);
    cout << "\nRoom Added Successfully!";

    return room;
}

void Room::displayRoom()
{
    cout << "\nRoom Number: " << room_number;

    if (is_wifi)
    {
        cout << "\nWifi provided";
    }
    else
    {
        cout << "\nWifi not provided";
    }

    switch (st)
    {
    case status::status_clean:
    {
        cout << "\nStatus: Cleaned";
        break;
    }
    case status::status_booked:
    {
        cout << "\nStatus: Booked";
        break;
    }
    case status::status_in_use:
    {
        cout << "\nStatus: In Use";
        break;
    }
    case status::status_maintenance:
    {
        cout << "\nStatus: Maintenance in Progress";
        break;
    }
    };

    switch (bed)
    {
    case bed_type::bed_type_single:
    {
        cout << "\nBeds: Single";
        break;
    }
    case bed_type::bed_type_double:
    {
        cout << "\nBeds: Double";
        break;
    }
    case bed_type::bed_type_master:
    {
        cout << "\nBeds: Master";
        break;
    }
    };

    cout << "\nCheck In Date: " << check_in_date;
    cout << "\nCheck Out Date: " << check_out_date;

    cout << "\nStaff In Charge: " << staff_in_charge;
    cout << "\nPrice: " << price;
    cout << "\nCapacity: " << capacity << endl;
}

void Room::setCapacity(int cap)
{
    this->capacity = cap;
}
