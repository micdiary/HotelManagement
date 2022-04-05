#include <iostream>

#include <stdexcept>
#include "premiumRoom.h"

PremiumRoom::PremiumRoom(int room_number, bool is_wifi, int capacity,
                         room_status status, bed_type bed_type,
                         string staff_in_charge, string name_occ, double price, bool smoking) : Room(room_number, is_wifi, capacity, status, bed_type, staff_in_charge, name_occ, price)
{
    this->is_smoking = smoking;
}

void PremiumRoom::setIsSmoking(bool smoking)
{
    is_smoking = smoking;
}

bool PremiumRoom::getIsSmoking() const
{
    return is_smoking;
}

PremiumRoom PremiumRoom::addRoom(int rno)
{
    bool wifi;
    string err_message;
    cout << "\nWifi (0 = false, 1 = true): ";
    cin >> wifi;

    if (wifi != 1 || wifi != 0)
    {
        err_message = "Wrong Wifi Input. Please try again.";
        throw(err_message);
    }

    PremiumRoom room(rno, wifi);

    room.setPrice(300);
    room.setRoomStatus(room_status::status_clean);

    cout << "\nPremium Room Added Successfully!";

    return room;
}

void PremiumRoom::displayRoom()
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
    case room_status::status_clean:
    {
        cout << "\nStatus: Cleaned";
        break;
    }
    case room_status::status_booked:
    {
        cout << "\nStatus: Booked";
        break;
    }
    case room_status::status_in_use:
    {
        cout << "\nStatus: In Use";
        break;
    }
    case room_status::status_maintenance:
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

PremiumRoom PremiumRoom::operator*(double reservation_discount)
{
    double temp_price;
    temp_price = this->getPrice() * reservation_discount;
    this->setPrice(temp_price);
    return *this;
}