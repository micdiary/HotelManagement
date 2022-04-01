#include <stdlib.h>
#include <iostream>
#include <string.h>
// #include <conio.h>

#include "common.h"
#include "hotelManagement.h"
#include "room.h"
#include "premiumRoom.h"
#include "doubleRoom.h"
#include "vipRoom.h"
#include "customer.h"

#include "hotelManagement.cpp"
#include "room.cpp"
#include "premiumRoom.cpp"
#include "doubleRoom.cpp"
#include "vipRoom.cpp"
#include "customer.cpp"

#define MAX 100

using namespace std;

const int Room::default_capacity = 2;
const room_status Room::default_status = room_status::status_maintenance;
const bed_type Room::default_bed_type = bed_type::bed_type_single;
const string Room::default_staff_in_charge = "NOBODY";
const string Room::default_name_occ = "NULL";
const double Room::default_price = 100;
const bool Room::default_is_smoking = false;
const bool Room::default_is_wifi = false;

const bool PremiumRoom::default_is_smoking = true;
const bool VipRoom::default_is_smoking = true;

int NO_OF_ROOMS = 0;
int NO_OF_CUSTOMERS = 0;

Room rooms[50];
PremiumRoom premium_rooms[50];
DoubleRoom double_rooms[50];
VipRoom vip_rooms[50];

Customer customers[50];

string RESERVATION_CODE = "1009";

int main()
{

    DoubleRoom temp_double_room(NO_OF_ROOMS, false, 5);
    temp_double_room.setPrice(200);
    temp_double_room.getRoomStatus();
    temp_double_room.setRoomStatus(room_status::status_clean);
    double_rooms[NO_OF_ROOMS] = temp_double_room;
    NO_OF_ROOMS++;

    Room temp_room(NO_OF_ROOMS, false);
    temp_room.setRoomStatus(room_status::status_clean);
    rooms[NO_OF_ROOMS] = temp_room;
    NO_OF_ROOMS++;

    PremiumRoom temp_premium_room(NO_OF_ROOMS, false);
    temp_premium_room.setPrice(300);
    temp_premium_room.setRoomStatus(room_status::status_clean);
    premium_rooms[NO_OF_ROOMS] = temp_premium_room;
    NO_OF_ROOMS++;

    VipRoom temp_vip_room(NO_OF_ROOMS, false, 20);
    temp_vip_room.setRoomStatus(room_status::status_clean);
    temp_vip_room.setPrice(350);
    vip_rooms[NO_OF_ROOMS] = temp_vip_room;
    NO_OF_ROOMS++;

    Customer c_temp("mic", 3, room_type::room_vip, reservation_status::reservation_wait_list, "1009");
    customers[NO_OF_CUSTOMERS] = c_temp;
    NO_OF_CUSTOMERS++;

    Customer c_temp1("adw", 2, room_type::room_premium, reservation_status::reservation_wait_list, "asd");
    customers[NO_OF_CUSTOMERS] = c_temp1;
    NO_OF_CUSTOMERS++;

    HotelManagement hm;
    Customer c;
    int i, j, opt, c_opt, rno;
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
            if (NO_OF_ROOMS == 0 || NO_OF_CUSTOMERS == 0)
            {
                cout << "\nRooms and Customers data is not available.\nPlease add the rooms and customers first.";
                cin >> opt;
            }
            else
            {
                for (i = 0; i < NO_OF_CUSTOMERS; i++)
                {
                    cout << i << ". " << customers[i].getName() << endl;
                }
                cout << "Which customer would you like to search? ";
                cin >> c_opt;
                c.search(c_opt);
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
