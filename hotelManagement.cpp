#include <iostream>
#include <stdlib.h>
#include <windows.h>

#include "hotelManagement.h"
#include "room.h"
#include "premiumRoom.h"
#include "doubleRoom.h"
#include "vipRoom.h"
#include "customer.h"

#include "common.h"
#include <ctime>

void HotelManagement::manageRooms(Array<Staff> arrayOfCleaners , Array<Staff> arrayOfManagers)
{
    Customer c;
    Room r;
    int opt, rno;
    string room_type_input, customer_name, message, err_message;
    room_type r_type;
    string cleaner;
    string manager;
    int temp_custID;
    string temp_custName;
    do
    {
        system("cls");
        cout << "######## Hotel Management #########\n";
        cout << "1. Add Rooms";
        cout << "\n2. Book Room";
        cout << "\n3. Check-In Room";
        cout << "\n4. Available Rooms";
        cout << "\n5. Check-Out Room";
        cout << "\n6. Exit";
        cout << "\n\nEnter Option: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            addRoomsOption();
            break;
        case 2:
            temp_custID = c.registerCustomer();

            cleaner = arrayOfCleaners.getAvailableStaff();
            cout << "Cleaner assigned: " << cleaner << endl;
            // arrayOfCleaners.showList();
            customers[temp_custID].setCleanerincharge(cleaner);

            manager = arrayOfManagers.getAvailableStaff();
            cout << "Manager assigned: " << manager << endl;
            // arrayOfCleaners.showList();
            customers[temp_custID].setManagerincharge(manager);

            system("cls");
            cout << "Room Booked Successfully.";
            Sleep(2000);
            break;
        case 3:
            cout << "\nRoom Number: ";
            cin >> rno;

            if (rno >= NO_OF_ROOMS || rno < 0)
            {
                err_message = "Wrong Room Number Input. Please try again.";
                throw(err_message);
            }

            cout << "\nRoom Type (base, double, premium, vip): ";
            cin >> room_type_input;

            if (room_type_input.compare("base") == 0)
            {
                r_type = room_type::room_base;
            }
            else if (room_type_input.compare("double") == 0)
            {
                r_type = room_type::room_double;
            }
            else if (room_type_input.compare("premium") == 0)
            {
                r_type = room_type::room_premium;
            }
            else if (room_type_input.compare("vip") == 0)
            {
                r_type = room_type::room_vip;
            }
            else
            {
                err_message = "Wrong Room Type Input. Please try again.";
                throw(err_message);
            }

            cout << "\nInput Customer's Name: ";
            cin >> customer_name;

            system("cls");
            message = r.checkIn(rno, customer_name, r_type);
            cout << message << endl;
            Sleep(2000);
            opt = 6;

            break;
        case 4:
            r.getAvailRoom();
            Sleep(5000);
            opt = 6;
            break;
        case 5:
            cout << "\nRoom Number: ";
            cin >> rno;

            cout << "\nRoom Type: (base, double, premium, vip)";
            cin >> room_type_input;

            if (room_type_input.compare("base") == 0)
            {
                r_type = room_type::room_base;
                temp_custName = rooms[rno].getNameOcc();
            }
            else if (room_type_input.compare("double") == 0)
            {
                r_type = room_type::room_double;
                temp_custName = double_rooms[rno].getNameOcc();
            }
            else if (room_type_input.compare("premium") == 0)
            {
                r_type = room_type::room_premium;
                temp_custName = premium_rooms[rno].getNameOcc();
            }
            else if (room_type_input.compare("vip") == 0)
            {
                r_type = room_type::room_vip;
                temp_custName = vip_rooms[rno].getNameOcc();
            }

            system("cls");
            r.checkOut(rno, r_type);

            for (int i = 0; i < NO_OF_CUSTOMERS; i++) {
                if (temp_custName == customers[i].getName() ){
                    temp_custID = i;
                }
            }

            cleaner = customers[temp_custID].getCleanerincharge();
            cout << "Cleaner deallocated: " << cleaner << endl;
            customers[temp_custID].setCleanerincharge("");
            arrayOfCleaners.setStaffAvailable(cleaner);
            //arrayOfCleaners.showList();

            manager = customers[temp_custID].getManagerincharge();
            cout << "Manager deallocated: " << manager << endl;
            customers[temp_custID].setManagerincharge("");
            arrayOfManagers.setStaffAvailable(manager);
            //arrayOfManagers.showList();

            cout << "Room checked out successfully." << endl;
            Sleep(2000);
            opt = 6;
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (opt != 6);
}

void HotelManagement::addRoomsOption()
{
    int opt;
    Room temp_room;
    PremiumRoom temp_premium_room;
    DoubleRoom temp_double_room;
    VipRoom temp_vip_room;

    do
    {
        cout << "1. Basic Room";
        cout << "\n2. Premium Room";
        cout << "\n3. Double Room";
        cout << "\n4. VIP Room";
        cout << "\n5. Exit";
        cout << "\n\nEnter Option: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            temp_room = temp_room.addRoom(NO_OF_ROOMS);
            rooms[NO_OF_ROOMS] = temp_room;
            cout << rooms[NO_OF_ROOMS];
            NO_OF_ROOMS++;
            break;
        case 2:
            temp_premium_room = temp_premium_room.addRoom(NO_OF_ROOMS);
            premium_rooms[NO_OF_ROOMS] = temp_premium_room;
            cout << premium_rooms[NO_OF_ROOMS];
            NO_OF_ROOMS++;
            break;
        case 3:
            temp_double_room = temp_double_room.addRoom(NO_OF_ROOMS);
            double_rooms[NO_OF_ROOMS] = temp_double_room;
            cout << double_rooms[NO_OF_ROOMS];
            NO_OF_ROOMS++;
            break;
        case 4:
            temp_vip_room = temp_vip_room.addRoom(NO_OF_ROOMS);
            vip_rooms[NO_OF_ROOMS] = temp_vip_room;
            cout << vip_rooms[NO_OF_ROOMS];
            NO_OF_ROOMS++;
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (opt != 5);
}