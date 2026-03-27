//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 1000 1212
// Output : 212

// test Case 2 
// Input : 1900 2500
// OutPut :400

// Test Case 3 
// Input : 2000 2999
// Output : 999


#include<iostream>
using namespace std;
int main () {
    int previous , current ;
    cin >> previous >> current;
    cout << current - previous << endl;
    return 0;
}