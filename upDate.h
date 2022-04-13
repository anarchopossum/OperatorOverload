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
    void displayDate() const;


    static int GetDateCount();
    int getMonth();
    int getDay();
    int getYear();
    string getMonthName();

    // OverLoaded Operators
    // Addition
    upDate operator+(int A);
    friend upDate operator+(int A, upDate D);
    upDate operator++();
    const upDate operator++(int A);
    upDate& operator+=(int a);


    // Subtraction
    upDate operator-(int A);
    int operator-(const upDate& D);
    friend upDate operator-(int A, upDate D);
    upDate operator--();
    const upDate operator--(int A);


    // equal and other operators
    upDate operator=(upDate D);
    bool operator==(upDate D);
    bool operator<(upDate D);
    bool operator>(upDate D);
    int daysBetween(upDate D);



    friend ostream& operator <<(ostream& os, const upDate &j);

    int julian();
};
int Greg2Julian(int M, int D, int Y);
void Julian2Greg(int JD, int &month, int &day, int &year);


#endif //OPERATOROVERLOAD_UPDATE_H

