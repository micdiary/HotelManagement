#include <iostream>

#include <stdexcept>
#include "vipRoom.h"

VipRoom::VipRoom(int room_number, bool is_wifi, int capacity,
                 status status, bed_type bed_type,
                 string staff_in_charge, string name_occ, double price, bool smoking) : Room(room_number, is_wifi, capacity, status, bed_type, staff_in_charge, name_occ, price)
{
    this->is_smoking = smoking;
}

void VipRoom::setIsSmoking(bool smoking)
{
    is_smoking = smoking;
}

bool VipRoom::getIsSmoking() const
{
    return is_smoking;
}

VipRoom VipRoom::addRoom(int rno)
{
    bool wifi;
    int capacity;

    cout << "\nWifi (0 = false, 1 = true): ";
    cin >> wifi;

    VipRoom room(rno, wifi);

    cout << "\nCapacity: ";
    cin >> capacity;
    room.setCapacity(capacity);
    room.setPrice(400);

    cout << "\nVip Room Added Successfully!";

    return room;
}

void VipRoom::displayRoom()
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
    cout << "\nCapacity: " << getCapacity();

    if (is_smoking)
    {
        cout << "\nSmoking allowed" << endl;
    }
    else
    {
        cout << "\nSmoking not allowed" << endl;
    }
}
