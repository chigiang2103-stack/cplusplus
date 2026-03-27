//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 10
// Output : 1788.9110640674 0.0000000217

// test Case 2 
// Input : 13
// OutPut : 2710.8866632413 0.0000000001

// Test Case 3
// Input : 9.3
// Output :1596.0075307391 0.0000000915

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main () {
    double x ; 
    cin >> x;
    double y1 ,y2;
    y1 = 4*(x*x + 10*x*sqrt(x)+3*x+1);
    y2 = (sin(3.14*x*x)+sqrt(x*x +1))/(pow(2.71,2*x) + cos(3.14*x/4));
    cout << fixed << setprecision(10) << y1 <<" "<< y2<< endl;
    return 0;
}