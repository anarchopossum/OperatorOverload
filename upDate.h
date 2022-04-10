//
// Created by Jasmine San Juan on 3/26/22.
//

#ifndef OPERATOROVERLOAD_UPDATE_H
#define OPERATOROVERLOAD_UPDATE_H
#include <iostream>
#include <string>
using namespace std;


class upDate {
private:
    //int date[3] = {5,11,1959};
    int* dptr;
    static int count;
public:

    upDate();
    upDate(int M, int D, int Y);
    upDate(int J);
    upDate(const upDate &date);
    ~upDate();


    void setDate(int M, int D, int Y);
    void incDate(int A);
    void decDate(int A);
    void displayDate();


    static int getDateCount();
    int getMonth();
    int getDay();
    int getYear();
    string getMonthName();

    // OverLoaded Operators
    // Addition
    upDate operator+(int A);
    friend upDate operator+(int A, upDate D);
    upDate operator++();
    // Subtraction
    upDate operator-(int A);
    friend upDate operator-(int A, upDate D);


    friend ostream& operator <<(ostream& os, const upDate &j);
};
int Greg2Julian(int M, int D, int Y);
void Julian2Greg(int JD, int &month, int &day, int &year);

#endif //OPERATOROVERLOAD_UPDATE_H
