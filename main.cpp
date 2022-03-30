#include <stdlib.h>
#include <iostream>
#include <string.h>
// #include <conio.h>

#include "common.h"
#include "hotelManagement.h"
#include "room.h"
#include "premiumRoom.h"

#include "hotelManagement.cpp"
#include "room.cpp"
#include "premiumRoom.cpp"

#define MAX 100

using namespace std;

const int Room::default_capacity = 2;
const status Room::default_status = status::status_clean;
const bed_type Room::default_bed_type = bed_type::bed_type_single;
const time_t Room::default_check_in_date = 0;
const time_t Room::default_check_out_date = 0;
const string Room::default_staff_in_charge = "NOBODY";
const string Room::default_name_occ = "NULL";
const double Room::default_price = 100;
const bool Room::default_is_smoking = false;
const bool Room::default_is_wifi = false;

const bool PremiumRoom::default_is_smoking = true;

int NO_OF_ROOMS = 0;
Room rooms[50];
PremiumRoom premium_rooms[50];

int main()
{
    class HotelManagement hm;
    int i, j, opt, rno;
    char ch;
    char pname[100];

    do
    {
        system("cls");
        cout << "######## Hotel Management #########\n";
        cout << "\n1. Manage Rooms";
        cout << "\n2. Search Customer";
        cout << "\n3. Guest Summary Report";
        cout << "\n4. Exit";
        cout << "\n\nEnter Option: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            hm.manageRooms();
            break;
        case 2:
            if (NO_OF_ROOMS == 0)
            {
                cout << "\nRooms data is not available.\nPlease add the rooms first.";
                cin >> opt;
            }
            else
            {
                // hm.checkIn();
            }
            break;
        case 3:
            if (NO_OF_ROOMS == 0)
            {
                cout << "\nRooms data is not available.\nPlease add the rooms first.";
                cin >> opt;
            }
            else
            {
                // hm.getAvailRoom();
            }
            break;
        case 4:
            cout << "\nEXITING";
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (opt != 4);
    return 0;
}
