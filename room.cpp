#include <iostream>

#include "room.h"

const status Room::default_status = status::status_clean;
const double Room::default_price = 100;
const bool Room::default_is_smoking = false;
const bool Room::default_is_wifi = false;

// Room::Room(int room_number,
//            int capacity)
// {
//     this->room_number = room_number;
//     this->capacity = capacity;
// }

Room Room::addRoom(int rno)
{
    Room room;

    cout << "\nWifi (0 = false, 1 = true): ";
    cin >> room.is_wifi;

    cout << "\nCapacity: ";
    cin >> room.capacity;

    cout << "\nRoom Added Successfully!";

    return room;
}

void Room::displayRoom(Room room)
{
    cout << "\nRoom Number: " << room.room_number;

    if (room.is_wifi)
    {
        cout << "\nWifi provided";
    }
    else
    {
        cout << "\nWifi not provided";
    }

    switch (room.st)
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

    switch (room.bed)
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

    cout << "\nCheck In Date: " << room.check_in_date;
    cout << "\nCheck Out Date: " << room.check_out_date;

    cout << "\nStaff In Charge: " << room.staff_in_charge;
    cout << "\nPrice: " << room.price;
    cout << "\nCapacity: " << room.capacity;
}

void Room::setCapacity(int cap)
{
    this->capacity = cap;
}
