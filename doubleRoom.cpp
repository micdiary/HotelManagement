#include <iostream>

#include <stdexcept>
#include "doubleRoom.h"

DoubleRoom::DoubleRoom(int room_number, bool is_wifi, int capacity,
                       room_status status,
                       string name_occ, double price) : Room(room_number, is_wifi, capacity, status, name_occ, price)
{
}

DoubleRoom DoubleRoom::addRoom(int rno)
{
    bool wifi;
    int capacity;
    string err_message;
    cout << "\nWifi (0 = false, 1 = true): ";
    cin >> wifi;

    if (wifi > 1 || wifi < 0)
    {
        err_message = "Wrong Wifi Input. Please try again.";
        throw(err_message);
    }

    DoubleRoom room(rno, wifi);

    cout << "\nCapacity: ";
    cin >> capacity;
    room.setCapacity(capacity);
    room.setPrice(200);
    room.setRoomStatus(room_status::status_clean);

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

    cout << "\nPrice: " << getPrice();
    cout << "\nCapacity: " << getCapacity() << endl;
}

DoubleRoom DoubleRoom::operator*(double reservation_discount)
{
    double temp_price;
    temp_price = this->getPrice() * reservation_discount;
    this->setPrice(temp_price);
    return *this;
}
