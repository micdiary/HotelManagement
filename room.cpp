#include <iostream>

#include "common.h"
#include "room.h"
#include <ctime>

// Room::Room(int room_number,
//            int capacity)
// {
//     this->room_number = room_number;
//     this->capacity = capacity;
// }

Room Room::addRoom(int rno)
{
    rooms[rno].room_number = rno;
    rooms[rno].st = status::status_clean;
    rooms[rno].bed = bed_type::bed_type_single;
    rooms[rno].check_in_date = 0;
    rooms[rno].check_out_date = 0;
    rooms[rno].price = 100;

    cout << "\nWifi (0 = false, 1 = true): ";
    cin >> rooms[rno].is_wifi;

    cout << "\nCapacity: ";
    cin >> rooms[rno].capacity;

    cout << "\nRoom Added Successfully!";

    return rooms[rno];
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
