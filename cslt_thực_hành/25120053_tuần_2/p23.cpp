//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 4 2
// Output : 27.06

// test Case 2 
// Input : 2 3
// OutPut : 28.26

// Test Case 3
// Input : 102.4 78.4
// Output :23271.50

#include<iostream>
#include<math.h>
using namespace std;
int main () {
    double edge , radius ;
    cin >> edge >> radius ;
    double s;
    if (edge <= radius ) {
        s = 3.14*radius*radius ;
    }
    else {
        s=(3*sqrt(3)*edge*edge)/4 + (3.14*radius*radius)/2 ;
    }
    printf("%.2f\n",s);
    return 0;
}