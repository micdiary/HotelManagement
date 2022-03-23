#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <conio.h>

#include "common.h"
#include "hotelManagement.cpp"
#include "room.cpp"

#define MAX 100

using namespace std;

// TODO:
const status Room::default_status = status::status_clean;
const double Room::default_price = 100;
const bool Room::default_is_smoking = false;
const bool Room::default_is_wifi = false;


int NO_OF_ROOMS = 0;
Room rooms[50];

int main()
{
    class HotelManagement hm;
    int i, j, opt, rno;
    char ch;
    char pname[100];

    // NO_OF_ROOMS = 0;
    // Room rooms[50];
    

    // for (i = 0; i < 10; i++)
    // {
    //     rooms[i] = rooms[i].addRoom(i);
    //     rooms[i].displayRoom(rooms[i]);
    // }

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
            if (NO_OF_ROOMS == 0)
            {
                cout << "\nRooms are not available.\nPlease add the rooms first.";
                cin >> opt;
            }
            else
            {
                cout << "Enter Customer Name: ";
                cin >> pname;
                // hm.searchCustomer(pname);
            }
            break;
        case 5:
            if (NO_OF_ROOMS == 0)
            {
                cout << "\nRooms are not available.\nPlease add the rooms first.";
                cin >> opt;
            }
            else
            {
                cout << "Enter Room Number : ";
                cin >> rno;
                // hm.checkOut(rno);
            }
            break;
        case 6:
            // hm.guestSummaryReport();
            break;
        case 7:
            cout << "\nTHANK YOU! FOR USING SOFTWARE";
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (opt != 7);
    cin >> opt;
}
