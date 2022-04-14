#include <iostream>
#include <windows.h>
#include "common.h"
#include "customer.h"
#include "room.h"
#include <ctime>
#include <string>

#include <stdlib.h>
#include <ctime>

Customer::Customer(string name, int room_number, room_type r_type,
                   reservation_status status, string code)
{
    this->name = name;
    this->room_number = room_number;
    this->r_type = r_type;
    this->reservation = status;
    this->reservation_code = code;
    this->cleaner_in_charge = "";
    this->manager_in_charge = "";
}

void Customer::search(int customer_id)
{

    int opt;
    double price;
    string in_charge;
    room_type type;

    int rno = customers[customer_id].getRoomNumber();

    system("cls");
    do
    {
        cout << "------------------------------------------" << endl;
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
            break;
        }
        case room_type::room_double:
        {
            price = double_rooms[rno].getPrice();
            break;
        }
        case room_type::room_premium:
        {
            price = premium_rooms[rno].getPrice();
            break;
        }
        case room_type::room_vip:
        {
            price = vip_rooms[rno].getPrice();
            break;
        }
        }

        cout << "Price of Room: $ " << price << endl;
        cout << "Cleaner in Charge: " << customers[customer_id].getCleanerincharge() << endl;
        cout << "Manager in Charge: " << customers[customer_id].getManagerincharge() << endl;
        cout << "------------------------------------------" << endl;
        cout << "1. Pay ";
        cout << "\n2. Exit";
        cout << "\n\nEnter Option: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            system("cls");
            payFees(customer_id);
            cout << "Payment for reservation is successful.";
            cout << "\nRoom is now reserved.";
            Sleep(2000);
            opt = 2;
            break;
        case 2:
            break;
        default:
            cout << "\nPlease Enter correct option";
            Sleep(1000);
            system("cls");
            break;
        }
    } while (opt != 2);
}

int Customer::registerCustomer()
{
    int opt, i;
    string name;
    int room_number = -1;
    room_type r_type;
    int temp_price;
    int temp_custID;
    string code;

    int noOfGuests;

    cout << "------------------------------------------" << endl;
    cout << "Enter Customer's Name: ";
    cin >> name;
    cout << "\nWhat type of room would you like to book? \n1:Base \n2:Double \n3:Premium \n4:VIP\n5:Exit\n";
    cout << "\nEnter room type (in number): ";
    cin >> opt;
    switch (opt)
    {
    case 1:
        for (i = 0; i < NO_OF_ROOMS; i++)
        {
            if (rooms[i].getRoomStatus() == room_status::status_clean && rooms[i].getPrice() >= 80)
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
            if (double_rooms[i].getRoomStatus() == room_status::status_clean && double_rooms[i].getPrice() >= 160)
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
            if (premium_rooms[i].getRoomStatus() == room_status::status_clean && premium_rooms[i].getPrice() >= 240)
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
            if (vip_rooms[i].getRoomStatus() == room_status::status_clean && vip_rooms[i].getPrice() >= 320)
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

    if (room_number == -1)
    {
        return -1;
    }

    cout << "------------------------------------------" << endl;
    cout << "Enter number of guests : ";
    cin >> noOfGuests;
    if (r_type == room_type::room_base){
        if (noOfGuests > 1){
            rooms[room_number] = rooms[room_number] + noOfGuests;
        }
    }
    else if(r_type == room_type::room_double){
        if(noOfGuests > 2){
            cout << "test 1" << endl;
            double_rooms[room_number] = double_rooms[room_number] + noOfGuests;
        }
    }
    else if(r_type == room_type::room_premium){
        if(noOfGuests > 3){
                        cout << "test 2" << endl;

            premium_rooms[room_number] = premium_rooms[room_number] + noOfGuests;
        }
    }
    else if(r_type == room_type::room_vip){
        if(noOfGuests > 3){
                        cout << "test 3" << endl;
            vip_rooms[room_number] = vip_rooms[room_number] + noOfGuests;
        }
    }
    else{
        rooms[room_number] = rooms[room_number];
    }
    cout << "------------------------------------------" << endl;
    cout << "Enter Reservation Code : ";
    cin >> code;

    bool discount_Code = false;
    int n = sizeof(DISCOUNT_CODE) / sizeof(DISCOUNT_CODE[0]);

    for (int i = 0; i < n; i++)
    {
        if (code == DISCOUNT_CODE[i])
        {
            discount_Code = true;
        }
    }

    if (discount_Code)
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
    temp_custID = NO_OF_CUSTOMERS;
    NO_OF_CUSTOMERS++;
    return temp_custID;
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

void Customer::setReservationStatus(reservation_status st)
{
    this->reservation = st;
}

room_type Customer::getRoomType()
{
    return r_type;
}

void Customer::payFees(int customer_id)
{
    int rno = customers[customer_id].getRoomNumber();
    customers[customer_id].setReservationStatus(reservation_status::reservation_confirm);
    //customers[customer_id].setCleanerincharge(string);


    switch (customers[customer_id].getRoomType())
    {
    case room_type::room_base:
    {
        rooms[rno].setRoomStatus(room_status::status_booked);
        break;
    }
    case room_type::room_double:
    {
        double_rooms[rno].setRoomStatus(room_status::status_booked);
        break;
    }
    case room_type::room_premium:
    {
        premium_rooms[rno].setRoomStatus(room_status::status_booked);
        break;
    }
    case room_type::room_vip:
    {
        vip_rooms[rno].setRoomStatus(room_status::status_booked);
        break;
    }
    }
}

void Customer::setCleanerincharge(string cleanerincharge){
    this->cleaner_in_charge = cleanerincharge;
}

string Customer::getCleanerincharge()
{
    return cleaner_in_charge;
}


void Customer::setManagerincharge(string managerincharge){
    this->manager_in_charge = managerincharge;
}

string Customer::getManagerincharge()
{
    return manager_in_charge;
}