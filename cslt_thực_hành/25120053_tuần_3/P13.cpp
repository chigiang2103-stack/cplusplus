//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 1999
// Output : Khong phai nam nhuan

// test Case 2 
// Input : 2013
// OutPut :Khong phai nam nhuan

// Test Case 3 
// Input : 2024
// Output :Nam nhuan 


#include<iostream>
using namespace std;
int main () {
    int year;
    cin >> year;
    if ((year%4==0 && year%100!=0 )|| year%400==0) {
        cout <<"Nam nhuan" <<endl;
    }
    else {
        cout <<"Khong phai nam nhuan"<<endl;
    }
    return 0;
}
