#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "hotelManagement.cpp"
#include "room.cpp"
#include "premiumRoom.cpp"
#include "doubleRoom.cpp"
#include "vipRoom.cpp"
#include "customer.cpp"
#include "init.cpp"
#include "staff.cpp"

using namespace std;

// initialize default values
const int Room::default_capacity = 2;
const room_status Room::default_status = room_status::status_maintenance;
const string Room::default_name_occ = "NULL";
const double Room::default_price = 100;
const bool Room::default_is_smoking = false;
const bool Room::default_is_wifi = false;

const bool PremiumRoom::default_is_smoking = true;
const bool VipRoom::default_is_smoking = true;

// initialize global variables
int NO_OF_ROOMS = 0;
int NO_OF_CUSTOMERS = 0;

Room rooms[50];
PremiumRoom premium_rooms[50];
DoubleRoom double_rooms[50];
VipRoom vip_rooms[50];

Customer customers[50];

string DISCOUNT_CODE[3] = {"1009", "servicerecovery", "angrycustomer"};

Staff cleaners[5];
Staff managers[5];

int main()
{
    Init init;
    init.initializeRooms();

    Staff cleaners[5];
    cleaners[0].setStaff("John", "cleaner", true);
    cleaners[1].setStaff("Mary", "cleaner", true);
    cleaners[2].setStaff("Tom", "cleaner", true);
    cleaners[3].setStaff("Heather", "cleaner", true);
    cleaners[4].setStaff("Trisha", "cleaner", true);
    int arrayElements = sizeof(cleaners) / sizeof(cleaners[0]);
	Array<Staff> arrayOfCleaners(cleaners, arrayElements); //class T = class Staff

    Staff managers[5];
    managers[0].setStaff("Ben", "manager", true);
    managers[1].setStaff("Jerry", "manager", true);
    managers[2].setStaff("Sheryl", "manager", true);
    managers[3].setStaff("Bob", "manager", true);
    managers[4].setStaff("Karen", "manager", true);
    int managerElements = sizeof(managers) / sizeof(managers[0]);
	Array<Staff> arrayOfManagers(managers, managerElements);


    HotelManagement hm;
    Customer c;
    int i, j, opt, c_opt, rno;
    
    string err_message;
    try
    {
        do
        {
            system("cls");
            cout << "######## Hotel Management #########\n";
            cout << "\n1. Manage Rooms";
            cout << "\n2. Search Customer";
            cout << "\n3. Exit";
            cout << "\n\nEnter Option: ";
            cin >> opt;
            switch (opt)
            {
            case 1:
                hm.manageRooms(arrayOfCleaners, arrayOfManagers);
                break;
            case 2:
                if (NO_OF_ROOMS == 0 || NO_OF_CUSTOMERS == 0)
                {
                    cout << "\nRooms and Customers data is not available.\nPlease add the rooms and customers first.";
                    Sleep(2000);
                }
                else
                {
                    for (i = 0; i < NO_OF_CUSTOMERS; i++)
                    {
                        cout << i << ". " << customers[i].getName() << endl;
                    }
                    cout << "Which customer would you like to search? ";
                    cin >> c_opt;

                    if (c_opt >= NO_OF_CUSTOMERS || c_opt < 0)
                    {
                        err_message = "Wrong Cusomter ID Input. Please try again.";
                        throw(err_message);
                    }
                    c.search(c_opt);
                }
                break;
            case 3:
                init.saveData();
                cout << "\nEXITING";
                break;
            default:
                cout << "\nPlease Enter correct option";
                break;
            }
        } while (opt != 3);
    }
    catch (string msg)
    {
        cout << msg << endl;
    }

    return 0;
}
