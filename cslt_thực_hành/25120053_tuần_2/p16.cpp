//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 56789
// Output : 5

// test Case 2 
// Input : 99999
// OutPut : 5

// Test Case 3
// Input : 11115
// Output :9

#include<iostream>
using namespace std;
int main () {
    int number_5_digits ;
    cin >> number_5_digits;
    int nut=0;
    while (number_5_digits!=0) {
        nut += number_5_digits%10;
        number_5_digits=number_5_digits/10;
    }
    cout << nut%10 << endl;
    return 0;
}