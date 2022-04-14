#include <iostream>

#include "common.h"
#include "room.h"
#include <ctime>
#include <windows.h>

Room::Room(int room_number, bool is_wifi, int capacity,
           room_status status,
         string name_occ, double price)
{
    this->room_number = room_number;
    this->is_wifi = is_wifi;
    this->capacity = capacity;
    this->st = status;
    this->name_occ = name_occ;
    this->price = price;
}

Room Room::addRoom(int rno)
{
    bool wifi;
    string err_message;
    cout << "\nWifi? (0 = false, 1 = true): ";
    cin >> wifi;

    if (wifi > 1 || wifi < 0)
    {
        err_message = "Wrong Wifi Input. Please try again.";
        throw(err_message);
    }
    
    Room room(rno, wifi);

    room.setRoomStatus(room_status::status_clean);
    cout << "-------------------------------------"<< endl;
    cout << "\nRoom Added Successfully!";

    return room;
}

ostream &operator<<(ostream &out, const Room &r)
{
    out << "\nRoom Number: " << r.room_number;

    if (r.is_wifi)
    {
        out << "\nWifi provided";
    }
    else
    {
        out << "\nWifi not provided";
    }

    switch (r.st)
    {
    case room_status::status_clean:
    {
        out << "\nStatus: Cleaned";
        break;
    }
    case room_status::status_booked:
    {
        out << "\nStatus: Booked";
        break;
    }
    case room_status::status_in_use:
    {
        out << "\nStatus: In Use";
        break;
    }
    case room_status::status_maintenance:
    {
        out << "\nStatus: Maintenance in Progress";
        break;
    }
    };

    out << "\nPrice: " << r.price;
    out << "\nCapacity: " << r.capacity << endl;

    return out;
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

void Room::setNameOcc(string name)
{
    this->name_occ = name;
}

int Room::getRoomNo()
{
    return room_number;
}

room_status Room::getRoomStatus()
{
    return st;
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

Room Room::operator+(double capacity_charge) 
{
    this->price = this->price + (50 * (capacity_charge-1)); // extra price per guest
    return *this;
} // if the customer is checking more than 1 guest, charge extra $50 per guest

bool Room::checkPayment(string customer_name)
{
    int cust_id;
    reservation_status st;
    string name;
    for (int i = 0; i < NO_OF_CUSTOMERS; i++)
    {
        name = customers[i].getName();
        st = customers[i].getReservationStatus();
        if (name.compare(customer_name) == 0)
        {
            if (st == reservation_status::reservation_confirm)
            {
                return true;
            }
        }
    }
    return false;
}

string Room::checkIn(int rno, string customer_name, room_type r_type)
{

    bool check;
    check = checkPayment(customer_name);

    if (check == true)
    {
        switch (r_type)
        {
        case room_type::room_base:
        {
            rooms[rno].setRoomStatus(room_status::status_in_use);
            rooms[rno].setNameOcc(customer_name);
            break;
        }
        case room_type::room_double:
        {
            double_rooms[rno].setRoomStatus(room_status::status_in_use);
            double_rooms[rno].setNameOcc(customer_name);
            break;
        }
        case room_type::room_premium:
        {
            premium_rooms[rno].setRoomStatus(room_status::status_in_use);
            premium_rooms[rno].setNameOcc(customer_name);
            break;
        }
        case room_type::room_vip:
        {
            vip_rooms[rno].setRoomStatus(room_status::status_in_use);
            vip_rooms[rno].setNameOcc(customer_name);
            break;
        }
        }

        return "Success. Customer checked in.";
    }
    else
    {
        return "Error. Customer not found.";
    }
}

void Room::checkOut(int rno, room_type r_type)
{

    switch (r_type)
    {
    case room_type::room_base:
    {
        rooms[rno].setRoomStatus(room_status::status_clean);
        rooms[rno].setPrice(100);
        break;
    }
    case room_type::room_double:
    {
        double_rooms[rno].setRoomStatus(room_status::status_clean);
        double_rooms[rno].setPrice(200);
        break;
    }
    case room_type::room_premium:
    {
        premium_rooms[rno].setRoomStatus(room_status::status_clean);
        premium_rooms[rno].setPrice(300);
        break;
    }
    case room_type::room_vip:
    {
        vip_rooms[rno].setRoomStatus(room_status::status_clean);
        vip_rooms[rno].setPrice(400);
        break;
    }
    }
}

void Room::getAvailRoom()
{
    for (int i = 0; i < NO_OF_ROOMS; i++)
    {
        if (rooms[i].getRoomStatus() == room_status::status_clean && rooms[i].getPrice() == 100)
        {
            cout << rooms[i];
        }
        else if (double_rooms[i].getRoomStatus() == room_status::status_clean && double_rooms[i].getPrice() == 200)
        {
            cout << double_rooms[i];
        }
        else if (premium_rooms[i].getRoomStatus() == room_status::status_clean && premium_rooms[i].getPrice() == 300)
        {
            cout << premium_rooms[i];
        }
        else if (vip_rooms[i].getRoomStatus() == room_status::status_clean && vip_rooms[i].getPrice() == 400)
        {
            cout << vip_rooms[i];
        }
        Sleep(3000);
    }
}