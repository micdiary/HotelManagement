#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>

#include "common.h"
#include "hotelManagement.h"
#include "room.h"
#include "premiumRoom.h"
#include "doubleRoom.h"
#include "vipRoom.h"
#include "customer.h"
#include "init.h"

using namespace std;

bool isInt(string line)
{
    char *p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

void Init ::initializeRooms()
{
    ifstream myfile("rooms.txt");
    string line;
    int count = 0;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (isInt(line) == true)
            {
                NO_OF_ROOMS = stoi(line);
            }
            else
            {
                if (line.compare("base") == 0)
                {
                    Room temp_room(count, false);
                    temp_room.setPrice(100);
                    temp_room.setRoomStatus(room_status::status_clean);
                    rooms[count] = temp_room;
                }
                else if (line.compare("double") == 0)
                {
                    DoubleRoom temp_double_room(count, false, 4);
                    temp_double_room.setPrice(200);
                    temp_double_room.setRoomStatus(room_status::status_clean);
                    double_rooms[count] = temp_double_room;
                }
                else if (line.compare("premium") == 0)
                {
                    PremiumRoom temp_premium_room(count, false);
                    temp_premium_room.setPrice(300);
                    temp_premium_room.setRoomStatus(room_status::status_clean);
                    premium_rooms[count] = temp_premium_room;
                }
                else if (line.compare("vip") == 0)
                {
                    VipRoom temp_vip_room(count, false, 4);
                    temp_vip_room.setPrice(400);
                    temp_vip_room.setRoomStatus(room_status::status_clean);
                    vip_rooms[count] = temp_vip_room;
                }
                count++;
            }
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";
}

void Init ::saveData()
{
    if (remove("rooms.txt") != 0)
        perror("Error deleting file");
    else
        puts("File successfully deleted");

    ofstream myfile;
    myfile.open("rooms.txt");
    myfile << NO_OF_ROOMS << endl;

    for (int i = 0; i < NO_OF_ROOMS; i++)
    {
        if (vip_rooms[i].getPrice() >= 320)
        {
            myfile << "vip" << endl;
        }
        else if (premium_rooms[i].getPrice() >= 240 && premium_rooms[i].getPrice() < 320)
        {
            myfile << "premium" << endl;
        }
        else if (double_rooms[i].getPrice() >= 160 && double_rooms[i].getPrice() < 240)
        {
            myfile << "double" << endl;
        }
        else if (rooms[i].getPrice() >= 80 && rooms[i].getPrice() < 160)
        {
            myfile << "base" << endl;
        }
    }
}
