/*
* Made by: Jasmine San Juan
* CECS 282
* Program 2 due March 1, 2022
*/
#ifndef MYDATE_MYDATE_H
#define MYDATE_MYDATE_H
#include <iostream>
#include <string>
using namespace std;


class myDate {
private:
    int month = 5, day = 11, year = 1959;
public:
    myDate();
    myDate(int m, int d, int y);
    int Greg2Julian(int month, int day, int year);
    int Julian2Greg(int JD, int &month, int &day, int &year);
    void display();
    void increaseDate(int n);
    void decreaseDate(int n);
    void addMonth();
    int daysBetween(myDate D);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    string dayName();
};


#endif //MYDATE_MYDATE_H
