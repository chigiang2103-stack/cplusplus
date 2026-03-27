#include<iostream>
using namespace std;

#include <iostream>
#include <cstring>
using namespace std;

struct Date {
    int day, month, year;
};

// TODO: Viết hàm kiểm tra năm nhuận
bool isLeap(int year) {
    if (year%4==0 && year%100!=0 || year%400==0) {
        return true;
    }
    return false;
}

// TODO: Viết hàm trả về số ngày của tháng
int daysInMonth(int month, int year) {
    switch (month){
        case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 : {
            return 31;
        }
        case 4 : case 6 : case 9 : case 11 : {
            return 30;
        }
        case 2 : {
            if (isLeap(year)) {
                return 29;
            }
            return 28;        
        }
    }
    return 0;
}

// TODO: Viết hàm nhập ngày
void inputDate(Date &d) {
    cin >> d.day >> d.month >> d.year ;
}

// TODO: Viết hàm so sánh 2 ngày (trả về true nếu d1 > d2)
bool isLater(const Date &d1, const Date &d2) {
    if (d1.year > d2.year) {
        return true;
    }
    else if ( d1.year < d2.year){
        return false;
    }
    else { 
        if (d1.month > d2.month) {
            return true;
        }
        else if (d1.month < d2.month) {
            return false;
        }
        else {
            if (d1.day > d2.day) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

// TODO: Viết hàm tính ngày mai
Date tomorrow(Date d) {
    if (d.day < daysInMonth(d.month , d.year )) {
        d.day++;
    }
    else {
        d.day=1;
        if (d.month < 12) {
            d.month++;
        }
        else {
            d.month=1;
            d.year++;
        }
    }
    return d;
}

// TODO: Viết hàm tính ngày hôm qua
Date yesterday(Date d) {
    if (d.day > 1 ) {
        d.day--;
    }
    else {
        if (d.month > 1) {
            d.month--;
            d.day=daysInMonth(d.month,d.year);
        }
        else {
            d.month=12;
            d.year--;
            d.day=31;
        }
    }
    return d;
}

int main() {
    Date d1, d2;
    inputDate(d1);
    inputDate(d2);

    if (isLater(d1, d2)) cout << "d1 is later than d2" << endl;
    else cout << "d1 is not later than d2" << endl;

    Date tmr = tomorrow(d1);
    Date ytd = yesterday(d2);

    cout << tmr.day << " " << tmr.month << " " << tmr.year << endl;
    cout << ytd.day << " " << ytd.month << " " << ytd.year << endl;

    return 0;
}

