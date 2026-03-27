//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 20
// Output : 2561327494111820313

// test Case 2 
// Input : 9
// OutPut :409113

// Test Case 3 
// Input :11
// Output :43954713

#include<iostream>
using namespace std;
int main () {
    unsigned long long giai_thua(unsigned int n);
    unsigned int n;
    cin >> n;
    unsigned long long sum=0;
    while (n>0) {
        sum+= giai_thua(n);
        n--;
    }
    cout << sum << endl;
    return 0;
}
unsigned long long giai_thua(unsigned int n) {
    if (n==1) return n;
    return n*(giai_thua(n-1));
}
