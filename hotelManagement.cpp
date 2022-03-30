#include <iostream>
#include <stdlib.h>

#include "hotelManagement.h"
#include "room.h"
#include "premiumRoom.h"
#include "common.h"
#include <ctime>

void HotelManagement::manageRooms()
{
    int opt;
    do
    {
        system("cls");
        cout << "1. Add Rooms";
        cout << "\n2. Check-In Room";
        cout << "\n3. Available Rooms";
        cout << "\n4. Search Customer";
        cout << "\n5. Check-Out Room";
        cout << "\n6. Exit";
        cout << "\n\nEnter Option: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            addRoomsOption();
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

    do
    {
        cout << "1. Basic Room";
        cout << "\n2. Premium Room";
        cout << "\n3. Double Rooms";
        cout << "\n4. VIP Room";
        cout << "\n5. Exit";
        cout << "\n\nEnter Option: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            temp_room = temp_room.addRoom(NO_OF_ROOMS);
            rooms[NO_OF_ROOMS] = temp_room;
            rooms[NO_OF_ROOMS].displayRoom();
            NO_OF_ROOMS++;
            break;
        case 2:
            temp_premium_room = temp_premium_room.addRoom(NO_OF_ROOMS);
            premium_rooms[NO_OF_ROOMS] = temp_premium_room;
            premium_rooms[NO_OF_ROOMS].displayRoom();
            NO_OF_ROOMS++;
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (opt != 5);
}