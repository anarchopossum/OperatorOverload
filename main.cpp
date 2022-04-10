#include <iostream>
#include "upDate.h"

int main() {
    upDate D1;
    upDate D2;
    D2.setDate(6,16,1997);
    D2.incDate(1);
    upDate D9 = D1 + 5;

//    upDate D3 = D2;
//    upDate D4(2459665); // Mar 26 2022
//    D1 = D2;
cout << D1.getMonthName() <<endl;
cout << "Day: " << D1.getDay() << " Month: " << D1.getMonth() << " Year: " << D1.getYear()<< endl;
cout << D2.getMonthName() <<endl;
cout << "Day: " << D2.getDay() << " Month: " << D2.getMonth() << " Year: " << D2.getYear()<< endl;
//cout << D2.Greg2Julian()<< endl;
cout << upDate::getDateCount()<< endl;
D2.displayDate();
cout << "Day: " << D9.getDay() << " Month: " << D9.getMonth() << " Year: " << D9.getYear()<< endl;//cout << D2;
    upDate D10 = D9 - 5;
    cout << "Day: " << D10.getDay() << " Month: " << D10.getMonth() << " Year: " << D10.getYear()<< endl;//cout << D2;
upDate D11 = 5 + D1;
D11.displayDate();
D11 = ++D11;
D11.displayDate();
//    std::cout << D1.getDay() << std::endl;
//    std::cout << D1.getMonth() << std::endl;
//    std::cout << D1.getYear() << std::endl;
    return 0;
}