#include <iostream>

#include "common.h"
#include "room.h"
#include <ctime>

Room::Room(int room_number, bool is_wifi, int capacity,
           room_status status, bed_type bed_type,
           string staff_in_charge, string name_occ, double price)
{
    this->room_number = room_number;
    this->is_wifi = is_wifi;
    this->capacity = capacity;
    this->st = status;
    this->bed = bed_type;
    this->staff_in_charge = staff_in_charge;
    this->name_occ = name_occ;
    this->price = price;
}

Room Room::addRoom(int rno)
{
    bool wifi;

    cout << "\nWifi (0 = false, 1 = true): ";
    cin >> wifi;

    Room room(rno, wifi);

    room.setRoomStatus(room_status::status_clean);
    
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

    cout << "\nStaff In Charge: " << staff_in_charge;
    cout << "\nPrice: " << price;
    cout << "\nCapacity: " << capacity << endl;
}

void Room::setRoomStatus(room_status status)
{
    this->st = status;
}

void Room::setPrice(double pr)
{
    this->price = pr;
}

void Room::setCapacity(int cap)
{
    this->capacity = cap;
}

int Room::getRoomNo()
{
    return room_number;
}

room_status Room::getRoomStatus()
{
    return st;
}

bed_type Room::getBedType()
{
    return bed;
}

string Room::getStaffInCharge()
{
    return staff_in_charge;
}

int Room::getCapacity()
{
    return capacity;
}

double Room::getPrice()
{
    return price;
}

string Room::getNameOcc()
{
    return name_occ;
}

bool Room::getIsWifi()
{
    return is_wifi;
}

Room Room::operator*(double reservation_discount)
{
    this->price = this->price * reservation_discount;
    return *this;
}