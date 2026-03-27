//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 10 200000
// Output : 220000

// test Case 2 
// Input : 23 1391.31
// OutPut : 35200

// Test Case 3
// Input : 19 1999
// Output :41779

#include<iostream>
using namespace std;
int main () {
    int quantity;
    cin >> quantity;
    float price ;
    cin >> price ;
    int total = round(quantity*price*1.1);
    cout << total << endl;
    return 0;
}