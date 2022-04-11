/*
* Made by: Jasmine San Juan
* CECS 282
* Program 2 due March 1, 2022
*/
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
#include "myDate.h"

myDate::myDate() {}
myDate::myDate(int m, int d, int y){
    month = m;
    day = d;
    year = y;
    if (month <=0 || month >=13 || day >31 || day<=0){
        month = 5, day = 11, year = 1959;
    }
}

// Math formulas to convert between calendar systems
int myDate::Greg2Julian(int month, int day, int year){

    int I = year;
    int J = month;
    int K = day;
    //pass day, month, year and return julian number
    int JD = K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
    return JD;
}
int myDate::Julian2Greg(int JD, int &month, int &day, int &year) {
    int I, J, K, L, N;
    L = JD + 68569;
    N = 4 * L / 146097;
    L = L - (146097 * N + 3) / 4;
    I = 4000 * (L + 1) / 1461001;
    L = L - 1461 * I / 4 + 31;
    J = 80 * L / 2447;
    K= L - 2447 * J / 80;
    L = J / 11;
    J= J + 2 - 12 * L;
    I = 100 * (N-49) + I + L;

    year = I;
    month = J;
    day = K;
    return 0;
}

void myDate::display(){
    string monthName;
    switch (month) {
        case 1:
            monthName = "January";
            break;
        case 2:
            monthName = "February";
            break;
        case 3:
            monthName = "March";
            break;
        case 4:
            monthName = "April";
            break;
        case 5:
            monthName = "May";
            break;
        case 6:
            monthName = "June";
            break;
        case 7:
            monthName = "July";
            break;
        case 8:
            monthName = "August";
            break;
        case 9:
            monthName = "September";
            break;
        case 10:
            monthName = "October";
            break;
        case 11:
            monthName = "November";
            break;
        case 12:
            monthName = "December";
            break;
        default:
            monthName = "Error";
            break;
    }
    cout << monthName << " " << day << ", " << year<<" ";
}

// Date increments and decrements
void myDate::addMonth() {
    month++;
    if (month > 12){
        month = 1;
        year++;
    }
    if (month == 2){
        if (year % 4 != 0 && day > 28){this->day = 28;}
        else if(year % 4 == 0 && day > 29){ this->day =29;}
    }
    if (month == 4 || month == 6 || month ==9 || month ==11){
        if (day > 30){
            this->day = 30;
        }
    }

    //this->display();

}
void myDate::increaseDate(int n) {
    int adder = Greg2Julian(month,day,year);
    int temp = adder+n;
    Julian2Greg(temp,month,day,year);
}
void myDate::decreaseDate(int n) {
    int adder = Greg2Julian(month,day,year);
    int temp=0;
    temp = adder-n;
    //if(adder>n){temp = adder-n;}
    //else if(adder<n){temp = n-adder;}
    Julian2Greg(temp,month,day,year);
}

// The Get Functions for bringing back int values of date attributes
int myDate::getMonth(){
    return month;
}
int myDate::getDay(){
    return day;
}
int myDate::getYear(){
    return year;
}

// returns the Julian day of the year
int myDate::dayOfYear(){
    int currYear = this->getYear();
    int startOfYear = this->Greg2Julian(1,1,currYear);
    int targetDate = this->Greg2Julian(month,day,year);


    return targetDate-startOfYear+1;
}

// finds the amount of days between two dates.
int myDate::daysBetween(myDate D) {

    int curDay = Greg2Julian(this->month,this->day, this->year);
    int Dday = Greg2Julian(D.getMonth(),D.getDay(),D.getYear());
    int val= Dday-curDay;
    return val;


}

// Returns the Weekday as a string
string myDate::dayName(){
    int JulDay = this->Greg2Julian(this->month,this->day,this->year);
    int result = JulDay % 7;
    switch (result) {
        case 0:
            return "Monday";
        case 1:
            return "Tuesday";
        case 2:
            return "Wednesday";
        case 3:
            return "Thursday";
        case 4:
            return "Friday";
        case 5:
            return "Saturday";
        case 6:
            return "Sunday";
        default:
            cout << result << endl;
            return "error";
    }
}
#include "myDate.h"
