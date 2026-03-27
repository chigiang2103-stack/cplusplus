//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 3.0 4.0 5.0
// Output : 12.00 6.00

// test Case 2 
// Input : 6.0 6.0 6.0
// OutPut : 18.00 15.59

// Test Case 3 
// Input : 13 6.8 9.3
// Output :29.10 30.29

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main () {
    double edge1,edge2,edge3;
    cin >> edge1 >> edge2 >> edge3;
    double dientich , chuvi;
    double p = (edge1 + edge2 + edge3)/2;
    dientich = sqrt(p*(p-edge1)*(p-edge2)*(p-edge3));
    chuvi = 2*p;
    cout << fixed << setprecision(2) << chuvi <<" "<< dientich<< endl;
    return 0;
}