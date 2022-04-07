//
// Created by Jasmine San Juan on 3/26/22.
//

#include "upDate.h"


int upDate::count = 0;

upDate::upDate() {
        dptr = new int[3]; // we can treat pointers as arrays
        dptr[0] = 5; // Month
        //*(dptr + 1) = 11; // you can use this format or array like [0] or [2]
        dptr[1] = 11; // Day
        dptr[2] = 1959; // Year
        count++;

}
upDate::upDate(int M, int D, int Y) {
    dptr[0] = M;
    dptr[1] = D;
    dptr[2] = Y;
    if (dptr[0] <=0 || dptr[0] >=13 || dptr[1] >31 || dptr[1]<=0){
        dptr[0] = 5, dptr[1] = 11, dptr[2] = 1959;
        count++;
    }
}
upDate::upDate(int A) {
    int I, J, K, L, N;
    L = A + 68569;
    N = 4 * L / 146097;
    L = L - (146097 * N + 3) / 4;
    I = 4000 * (L + 1) / 1461001;
    L = L - 1461 * I / 4 + 31;
    J = 80 * L / 2447;
    K= L - 2447 * J / 80;
    L = J / 11;
    J= J + 2 - 12 * L;
    I = 100 * (N-49) + I + L;

    dptr[2] = I; // Year
    dptr[0] = J; // Month
    dptr[1] = K; // Day
    count++;
}
upDate::upDate(const upDate &date) {
    dptr = new int[3];
    dptr[0] = date.dptr[0];
    dptr[1] = date.dptr[1];
    dptr[2] = date.dptr[2];
    count++;
}
upDate::~upDate() {
    delete[] dptr;
    count--;
}

void upDate::setDate(int M, int D, int Y) {
    dptr[0] = M;
    dptr[1] = D;
    dptr[2] = Y;
    if (dptr[0] <=0 || dptr[0] >=13 || dptr[1] >31 || dptr[1]<=0){
        dptr[0] = 5, dptr[1] = 11, dptr[2] = 1959;
    }
}

// Date Modifiers
// these can add and subtract values
void upDate::incDate(int A) {
    int convert = Greg2Julian(this->getMonth(),this->getDay(),this->getYear());
    convert += A;
    Julian2Greg(convert, dptr[0],dptr[1],dptr[2]);
}
void upDate::decDate(int A) {
    int convert = Greg2Julian(this->getMonth(),this->getDay(),this->getYear());
    convert -= A;
    Julian2Greg(convert, dptr[0],dptr[1],dptr[2]);

}

// Return Function functions
// These will return the requested attributes
int upDate::getDateCount(){return count;}
int upDate::getMonth() {return dptr[0];}
int upDate::getDay()   {return dptr[1];}
int upDate::getYear()  {return dptr[2];}


string upDate::getMonthName(){
    string monthName;
    switch (dptr[0]) {
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
    return monthName;
}


void upDate::displayDate()
{
    cout << *this << endl;
}

ostream &operator<<(ostream& os, const upDate &J) {
    upDate temp(J);
    os << temp.dptr[0] <<"/"<<temp.dptr[1]<<"/"<<temp.dptr[2];
    return os;
}

upDate upDate::operator+(int a)
{
    upDate temp(*this);
    temp.incDate(a);
    return temp;
}

upDate upDate::operator-(int a)
{
    upDate temp(*this);
    temp.decDate(a);
    return temp;
}

void Julian2Greg(int JD, int &month, int &day, int &year) {
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
}

int Greg2Julian(int m,int d,int y) {
    int I = y;  // Year
    int J = m;  // Month
    int K = d;  // Day
    //pass day, month, year and return julian number
    int JD = K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
    return JD;
}