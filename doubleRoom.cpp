#include <iostream>

#include <stdexcept>
#include "doubleRoom.h"

DoubleRoom::DoubleRoom(int room_number, bool is_wifi, int capacity,
                         status status, bed_type bed_type,
                         string staff_in_charge, string name_occ, double price) : Room(room_number, is_wifi, capacity, status, bed_type, staff_in_charge, name_occ, price)
{
}

// void DoubleRoom::set(bool smoking)
// {
//     is_smoking = smoking;
// }

// bool DoubleRoom::getIsSmoking() const
// {
//     return is_smoking;
// }

DoubleRoom DoubleRoom::addRoom(int rno)
{
    bool wifi;
    int capacity;

    cout << "\nWifi (0 = false, 1 = true): ";
    cin >> wifi;

    DoubleRoom room(rno, wifi);
    
    cout << "\nCapacity: ";
    cin >> capacity;
    room.setCapacity(capacity);
    room.setPrice(200);

    cout << "\nDouble Room Added Successfully!";

    return room;
}

void DoubleRoom::displayRoom()
{
    cout << "\nRoom Number: " << getRoomNo();

    if (getIsWifi())
    {
        cout << "\nWifi provided";
    }
    else
    {
        cout << "\nWifi not provided";
    }

    switch (getRoomStatus())
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

    switch (getBedType())
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

    cout << "\nStaff In Charge: " << getStaffInCharge();
    cout << "\nPrice: " << getPrice();
    cout << "\nCapacity: " << getCapacity() << endl;
}
