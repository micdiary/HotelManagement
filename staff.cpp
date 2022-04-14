#include <iostream>
#include <stdlib.h>
#include <windows.h>

#include "staff.h"
#include <ctime>

using namespace std;

template<class T>
Array<T>::Array(T* d, int s){
  this->size  = s; 
  data = new T [size];
  this->data = d;
}
template<class T>
void Array<T>::showList(){
  cout << "showList() " << endl;
  for ( int j = 0; j < size; j++ ) {
    cout << data[j] << " " << endl;
    }
}
template<class T>
string Array<T>::getAvailableStaff(){
  for ( int j = 0; j < size; j++ ) {
    if (data[j].getAvail()){
      data[j].setnotAvail();
      return data[j].getName();
    }
  }
  return "None Available";
}
template<class T>
void Array<T>::setStaffAvailable(string name){
  for (int j = 0; j < size; j++ ) {
     if (name == data[j].getName()){
         data[j].setToAvail();
     }
    }
}


void Staff::setStaff(string name, string type, bool is_Available) {
  	this -> name = name;
    this-> type = type;
    this-> is_Available = is_Available;
}
bool Staff::getAvail() {
  	return this->is_Available;
}
string Staff::getName() {
  	return this->name;
}
void Staff::setnotAvail() {
  	 this->is_Available = false;
}
void Staff::setToAvail() {
  	 this->is_Available = true;
}
ostream& operator<<(ostream &out, const Staff& staff) {
  out << staff.name << " " << staff.type << " " << staff.is_Available;
  return out;
}