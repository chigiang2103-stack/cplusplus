//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 7
// Output : 140

// test Case 2 
// Input : 13
// OutPut : 819

// Test Case 3 
// Input : 20
// Output :2870


#include<iostream>
using namespace std;
int main () {
    unsigned int n; 
    cin >> n;
    unsigned long long temp =0;
    while (n>0) {
        temp+=n*n;
        n=n-1;
    }
    cout << temp << endl;
    return 0;

}
