#include <iostream>

#include "common.h"
#include "customer.h"
#include "room.h"
#include <ctime>
#include <string>

Customer::Customer(string name, int room_number, room_type r_type,
                   reservation_status status, string code)
{
    this->name = name;
    this->room_number = room_number;
    this->r_type = r_type;
    this->reservation = status;
    this->reservation_code = code;
}

void Customer::registerCustomer()
{
    int opt, i;
    string name;
    int room_number = -1;
    room_type r_type;
    int temp_price;
    string code;

    cout << "Enter Customer's Name: ";
    cin >> name;
    cout << "\nWhat type of room would you like to book? \n1:Base \n2:Double \n3:Premium \n4:VIP\n";
    cin >> opt;
    switch (opt)
    {
    case 1:
        for (i = 0; i < NO_OF_ROOMS; i++)
        {
            if (rooms[i].getRoomStatus() == room_status::status_clean)
            {
                room_number = rooms[i].getRoomNo();
                r_type = room_type::room_base;
                rooms[i].setRoomStatus(room_status::status_booked);
                break;
            }
        }
        break;
    case 2:
        for (i = 0; i < NO_OF_ROOMS; i++)
        {
            // cout << double_rooms[i].getRoomStatus();
            if (double_rooms[i].getRoomStatus() == room_status::status_clean)
            {
                room_number = double_rooms[i].getRoomNo();
                r_type = room_type::room_double;
                double_rooms[i].setRoomStatus(room_status::status_booked);
                break;
            }
        }
        break;
    case 3:
        for (i = 0; i < NO_OF_ROOMS; i++)
        {
            if (premium_rooms[i].getRoomStatus() == room_status::status_clean)
            {
                room_number = premium_rooms[i].getRoomNo();
                r_type = room_type::room_premium;
                premium_rooms[i].setRoomStatus(room_status::status_booked);
                break;
            }
        }
        break;
    case 4:
        for (i = 0; i < NO_OF_ROOMS; i++)
        {
            if (vip_rooms[i].getRoomStatus() == room_status::status_clean)
            {
                room_number = vip_rooms[i].getRoomNo();
                r_type = room_type::room_vip;
                vip_rooms[i].setRoomStatus(room_status::status_booked);
                break;
            }
        }
        break;
    default:
        break;
    }

    if (room_number == -1){
        return;
    }

    cout << "Enter Reservation Code : ";
    cin >> code;

    if (code.compare(RESERVATION_CODE) == 0)
    {
        switch (r_type)
        {
        case room_type::room_base:
        {
            rooms[room_number] = rooms[room_number] * 0.8;
            break;
        }
        case room_type::room_double:
        {
            double_rooms[room_number] = double_rooms[room_number] * 0.8;
            break;
        }
        case room_type::room_premium:
        {
            premium_rooms[room_number] = premium_rooms[room_number] * 0.8;
            break;
        }
        case room_type::room_vip:
        {
            vip_rooms[room_number] = vip_rooms[room_number] * 0.8;
            break;
        }
        }
    }

    Customer c(name, room_number, r_type, reservation_status::reservation_wait_list, code);
    customers[NO_OF_CUSTOMERS] = c;
    NO_OF_CUSTOMERS++;
}

void Customer::search(int customer_id)
{

    int opt;
    double price;
    string in_charge;

    int rno = customers[customer_id].getRoomNumber();

    do
    {
        system("cls");

        cout << "Customer Name: " << customers[customer_id].getName() << endl;
        cout << "Room Number: " << rno << endl;
        cout << "Reservation Status: ";
        switch (customers[customer_id].getReservationStatus())
        {
        case reservation_status::reservation_confirm:
            cout << "Confirmed" << endl;
            break;
        case reservation_status::reservation_wait_list:
            cout << "Wait List" << endl;
            break;
        case reservation_status::reservation_expire:
            cout << "Expired" << endl;
            break;
        }

        switch (customers[customer_id].getRoomType())
        {
        case room_type::room_base:
        {
            price = rooms[rno].getPrice();
            in_charge = rooms[rno].getStaffInCharge();
            break;
        }
        case room_type::room_double:
        {
            price = double_rooms[rno].getPrice();
            in_charge = double_rooms[rno].getStaffInCharge();

            break;
        }
        case room_type::room_premium:
        {
            price = premium_rooms[rno].getPrice();
            in_charge = premium_rooms[rno].getStaffInCharge();

            break;
        }
        case room_type::room_vip:
        {
            price = vip_rooms[rno].getPrice();
            in_charge = vip_rooms[rno].getStaffInCharge();

            break;
        }
        }

        cout << "Price of Room: " << price << endl;
        cout << "In Charge: " << in_charge << endl;

        cout << "1. Pay ";
        cout << "\n2. Exit";
        cout << "\n\nEnter Option: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            // addRoomsOption();
            break;
        case 2:
            // c.registerCustomer();
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (opt != 2);
}

string Customer::getName()
{
    return name;
}

int Customer::getRoomNumber()
{
    return room_number;
}

reservation_status Customer::getReservationStatus()
{
    return reservation;
}

room_type Customer::getRoomType()
{
    return r_type;
}