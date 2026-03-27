//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 42.195 1 59 40.2
// Output : 2.84 21.16

// test Case 2 
// Input : 40.19 1 39 36.4
// OutPut :2.48 24.21

// Test Case 3
// Input : 39.19 1 14 49.7
// Output :1.91 31.42

#include<iostream>
using namespace std;
int main () {
    double km , hour ,minute ,second ;
    cin >> km >> hour >> minute >> second ;
    double pace , speed ;
    pace = (hour*60 + minute + second/60)/(km);
    speed = km/(hour + minute/60 + second/3600);
    printf("%.2f %.2f\n",pace,speed);
    return 0;
}