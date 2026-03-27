//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 19 99000
// Output : 521052.63

// test Case 2 
// Input : 88 424242
// OutPut : 482093.18

// Test Case 3
// Input : 36 180000
// Output :500000.00

#include<iostream>
using namespace std;
int main () {
    double percent , quota ;
    cin >> percent >> quota;
    double res = quota*100/percent ;
    printf("%.2f\n",res);
    return 0;
}