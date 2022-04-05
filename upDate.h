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
public:
    upDate();
    upDate(int M, int D, int Y);
    upDate(int J);
    ~upDate();
    void setDate(int M, int D, int Y);
    void incDate(int A);
    void decDate(int A);
    int getMonth();
    int getDay();
    int getYear();
    string getMonthName();
    int Julian();
};


#endif //OPERATOROVERLOAD_UPDATE_H
