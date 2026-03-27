//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 99 100
// Output : 100 99 

// test Case 2 
// Input : 1 1000000
// OutPut : 1000000 1

// Test Case 3
// Input : 5 9
// Output :9 5

#include<iostream>
using namespace std;
int main () {
    int a ,b;
    cin >> a >> b ;
    int temp;
    temp = a;
    a = b ;
    b = temp ;
    cout << a << " " << b << endl;
    return 0;
}