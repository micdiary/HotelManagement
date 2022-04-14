#pragma once

#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include <stdlib.h>
#include <windows.h>

#include "common.h"

template<class T>
class Array {
private:
	T* data;
	int size;
public:
	Array(T* d, int s);
	void showList();
	string getAvailableStaff();
	void setStaffAvailable(string);
};
class Staff {
	string name;
	string type;
    bool is_Available;
	friend ostream& operator<<(ostream&, const Staff&);
public:
	void setStaff(string, string, bool);
	bool getAvail();
	string getName();
	void setnotAvail();
	void setToAvail();
};

#endif
